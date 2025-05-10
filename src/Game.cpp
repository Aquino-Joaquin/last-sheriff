#include "Game.h"

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
    
}
void Game::init(){
    
    map.init_map();
    my_player = Player(
        100,
        "resources/wabbit_alpha.png",
        {5,5}
    );
    my_gun = Gun(
        {my_player.get_position()},
        "resources/wabbit_alpha.png",
        10,
        0.5
    );
    Zombie juan(100,"resources/wabbit_alpha.png",{15,5},0.1);
    Zombie pepe(200,"resources/wabbit_alpha.png",{20,5},0.1);
    Zombie carlos(200,"resources/wabbit_alpha.png",{30,5},0.1);

    enemies.clear();
    enemies.emplace_back(100, "resources/wabbit_alpha.png", Vector2{15, 5}, 0.1);
    enemies.emplace_back(200, "resources/wabbit_alpha.png", Vector2{20, 5}, 0.1);
    enemies.emplace_back(200, "resources/wabbit_alpha.png", Vector2{30, 5}, 0.1);




}
void Game::draw(){
    map.draw_map();
    my_player.draw_on_map();
    my_gun.draw();
    
    for(auto& zombie:enemies){
        zombie.draw_on_map();
    }

    for(auto& bullet: my_gun.bullets){
        bullet.draw();
    }
}
void Game::update(){
    my_player.move_player(map);
    my_gun.update(my_player.get_position());
    
    for(auto& zombie:enemies){
        zombie.attack(my_player,map,20,enemies);
        zombie.check_alive(my_gun);
    }
    for(auto& bullet: my_gun.bullets){
        bullet.update();
    }
}
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
                map.draw_map();
                draw();
                update();
                if (IsKeyDown(KEY_SPACE)) {
                    my_gun.fire_gun();
                }
            } else {
                menu_option = 2; 
            }
        }

        else if (menu_option == 2) {
            end_menu.display_menu();
            int end_choice = end_menu.check_buttons();

            if (end_choice == 0) {
                
                init(); 
                menu_option = start_menu.start;
            } else if (end_choice == 1) {
                menu_option = start_menu.end;
            }
        }

        EndDrawing();
    }
}
Game::~Game(){
    
    CloseWindow();
}