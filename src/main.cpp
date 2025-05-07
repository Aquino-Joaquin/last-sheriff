#include "raylib.h"
#include "Map.h"
#include "resource_dir.h"  // Utility header for setting the resource directory
#include <iostream>
using namespace std;
#include "Menu.h"
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Gun.h"

int main() {
    // Initialize the game window
    InitWindow(1280, 720, "Game Project");
    SetTargetFPS(60);

    // Create map with size based on screen height
    int map_size = GetScreenHeight();
    Map world_map(map_size / 40, map_size / 40);

    // Create UI buttons for the menu
    Button start_button("resources/start_button.png", {100, 100});
    Button end_button("resources/exit_button.png", {300, 300});
    Menu game_menu("resources/menu_background.png", start_button, end_button);

    // Create the player character
    Player character(100, "resources/wabbit_alpha.png",{5,5});
    Zombie enemy(100,"resources/wabbit_alpha.png",{10,10},0.4);

    Gun my_gun("Gun",{5,5},"resources/wabbit_alpha.png",10,100,0.5);
    

    int menu_option = -1; // -1 means menu is currently active

    while (!WindowShouldClose() && menu_option != game_menu.end) {
        
        BeginDrawing();

        if (menu_option == -1) {
            // Display the main menu
            ClearBackground(GRAY);
            game_menu.display_menu();
            menu_option = game_menu.check_buttons();
        }

        if (menu_option == game_menu.start) {
            // Start the game: draw map and move player
            ClearBackground(GRAY);
            world_map.draw_map();
            character.move_player(world_map);
            enemy.attack(character,world_map,1);
            my_gun.update(world_map,character);
            if(IsKeyDown(KEY_SPACE)){
                my_gun.fire_gun(world_map);
            }
            for(auto& bullet: my_gun.bullets){
                bullet.draw(world_map);
            }
            for(auto& bullet: my_gun.bullets){
                bullet.update();
            }
            
            
        } else if (menu_option == game_menu.end) {
            // Exit option selected
            menu_option = game_menu.end;
        }

        EndDrawing();
    }

    // Cleanup and close the window
    CloseWindow();
    return 0;
}
