#include "Game.h"

// Constructor
Game::Game() {
    InitWindow(1280, 720, "Game Project");
    SetTargetFPS(60);
    InitAudioDevice();

    start_menu = Menu(
        "resources/background_startMenu.png",
        "resources/start_menu.wav",
        Button("resources/start_button.png", {450, 150}),
        Button("resources/exit_button.png", {450, 400})
        
    );
    end_menu = Menu(
        "resources/background_EndGame.png",
        "resources/end_menu.wav",
        Button("resources/retry_button.png", {450, 150}),
        Button("resources/exit_button.png", {450, 400})
    );

    round = 1;               // Start from round 1
    zombies_killed = 0;      // Counter for dead zombies
    enviroment_sound = LoadSound("resources/zombie.wav");
    
}

// Initialize or reset the game state
void Game::init() {
    map.init_map();

    Texture2D player_skin = LoadTexture("resources/cowboy.png");
    Animation player_animated(player_skin, 14, 10, 1.f / 9.f, 0.5f, 0, 7, 10, 13);
    my_player = Player(100, {5, 5}, player_animated,{25,20,20,35});
    my_gun = Gun({my_player.get_position()}, "resources/wabbit_alpha.png", "resources/shot.mp3", 10, 0.5);

    zombie_texture = LoadTexture("resources/zombie.png");

    round = 1;
    zombies_killed = 0;
    spawn_zombies();
}

// Spawn zombies based on current round number
void Game::spawn_zombies() {
    enemies.clear(); 

    zombies_to_spawn = 3 + round * 2;
    base_zombie_life = 100 + (round - 1) * 20;
    zombie_speed = 0.1f;
    zombie_spawn_timer = 0.0f;
    spawning = true;
}

void Game::update_zombie_spawning(float deltaTime) {
    if (spawning && zombies_to_spawn > 0) {
        zombie_spawn_timer += deltaTime;

        if (zombie_spawn_timer >= zombie_spawn_delay) {
            zombie_spawn_timer = 0.0f;

            // Usar textura ya cargada
            Animation zombie_animated(zombie_texture, 36, 8, 1.0f / 16.0f, 0.8f, 4, 11, 0, 0);
            Rectangle hitBoxRec = {40,30,20,40};
            enemies.emplace_back(
                base_zombie_life,
                zombie_spawn_position,
                zombie_speed,
                zombie_animated,
                hitBoxRec
            );

            zombies_to_spawn--;
        }

        if (zombies_to_spawn == 0) {
            spawning = false;
        }
    }
}

// Draw everything on screen
void Game::draw() {
    map.draw_map();
    my_player.draw_on_map();
    //my_gun.draw();

    for (auto& zombie : enemies) {
        zombie.draw_on_map();
    }

    for (auto& bullet : my_gun.bullets) {
        bullet.draw();
    }

    // Display current round
    DrawText(TextFormat("Round: %d", round), 20, 20, 30, RED);
    DrawText(TextFormat("Enemies Left: %d", alive_zombies), GetScreenWidth() - 250, 20, 30, RED);
}

// Update game logic
void Game::update() {
    float deltaTime = GetFrameTime(); // Time elapsed since last frame
    update_zombie_spawning(deltaTime); // Spawn zombies one at a time

    my_player.move_player(map);
    my_gun.update(my_player.get_position());

    alive_zombies = 0;

    for (auto& zombie : enemies) {
        if (zombie.is_alive()) {
            alive_zombies++;
            int damage = 20 + (round - 1) * 5; // Zombies get stronger each round
            zombie.attack(my_player, map, damage, enemies);
            zombie.take_damage(my_gun);
        }
    }

    for (auto& bullet : my_gun.bullets) {
        bullet.update();
    }

    // Start next round only when all zombies are dead and spawning is finished
    if (!spawning && alive_zombies == 0) {
        round++;
        spawn_zombies();
    }
}

// Main game loop
void Game::run() {
    int menu_option = -1;

    while (!WindowShouldClose() && menu_option != start_menu.end) {
        BeginDrawing();

        if (menu_option == -1) {
            ClearBackground(GRAY);
            start_menu.display_menu();
            menu_option = start_menu.check_buttons();

            if (menu_option == start_menu.start) {
                init();
            }
        }

        else if (menu_option == start_menu.start) {
            if(IsSoundPlaying(start_menu.menu_sound)){
                StopSound(start_menu.menu_sound);
            }
            if(IsSoundPlaying(end_menu.menu_sound)){
                StopSound(end_menu.menu_sound);
            }
            if (my_player.is_alive()) {
                ClearBackground(BLACK);
                draw();
                update();
                if(alive_zombies > 0 && !IsSoundPlaying(enviroment_sound)){
                    PlaySound(enviroment_sound);
                }
                if (IsKeyDown(KEY_SPACE)) {
                    my_gun.fire_gun(my_player);
                }
            } else {
                menu_option = 2; // Player died -> go to end menu
            }
        }

        else if (menu_option == 2) {
            end_menu.display_menu();
            int end_choice = end_menu.check_buttons();

            if (end_choice == 0) {
                init(); // Restart game
                menu_option = start_menu.start;
            } else if (end_choice == 1) {
                menu_option = start_menu.end; // Exit game
            }
        }

        EndDrawing();
    }
}

// Destructor
Game::~Game() {
    CloseAudioDevice();
    CloseWindow();
}
