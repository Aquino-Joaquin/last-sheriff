#include "Game.h"

// Constructor
Game::Game() {
    InitWindow(1280, 720, "Game Project");
    SetTargetFPS(60);

    start_menu = Menu(
        "resources/menu_background.png",
        Button("resources/start_button.png", {100, 100}),
        Button("resources/exit_button.png", {300, 300})
    );
    end_menu = Menu(
        "resources/menu_background.png",
        Button("resources/start_button.png", {100, 100}),
        Button("resources/exit_button.png", {300, 300})
    );

    round = 1;               // Start from round 1
    zombies_killed = 0;      // Counter for dead zombies
}

// Initialize or reset the game state
void Game::init() {
    map.init_map();
    my_player = Player(100, "resources/wabbit_alpha.png", {5, 5});
    my_gun = Gun({my_player.get_position()}, "resources/wabbit_alpha.png", 10, 0.5);

    round = 1;
    zombies_killed = 0;
    spawn_zombies();
}

// Spawn zombies based on current round number
void Game::spawn_zombies() {
    enemies.clear();
    int zombie_count = 3 + round * 2;                    // More zombies each round
    int base_life = 100 + (round - 1) * 20;              // Stronger zombies
    float speed = 0.1f;
    float spacing = 5.0f;

    for (int i = 0; i < zombie_count; ++i) {
        Vector2 spawn_pos = {15 + i * spacing, 5};       // Spread out horizontally
        enemies.emplace_back(base_life, "resources/wabbit_alpha.png", spawn_pos, speed);
    }
}

// Draw everything on screen
void Game::draw() {
    map.draw_map();
    my_player.draw_on_map();
    my_gun.draw();

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
    my_player.move_player(map);
    my_gun.update(my_player.get_position());

    alive_zombies = 0;

    for (auto& zombie : enemies) {
        if (zombie.is_alive()) {
            alive_zombies++;
            // Zombie damage increases each round
            int damage = 20 + (round - 1) * 5;
            zombie.attack(my_player, map, damage, enemies);
            zombie.take_damage(my_gun);
        }
    }

    for (auto& bullet : my_gun.bullets) {
        bullet.update();
    }

    // If all zombies are dead, go to next round
    if (alive_zombies == 0) {
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
            if (my_player.is_alive()) {
                ClearBackground(BLACK);
                draw();
                update();

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
    CloseWindow();
}
