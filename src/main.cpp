

#include "raylib.h"
#include "Map.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include <iostream>
using namespace std;
#include "Menu.h"





int main ()
{
	

	InitWindow(1280, 720 , "Game Project");
	SetTargetFPS(60);
	
	int map_size = GetScreenHeight();
	Map world_map(map_size/40,map_size/40);
	Button start_button("resources/start_button.png",{100,100});
	Button end_button("resources/exit_button.png",{300,300});
	Menu game_menu("resources/menu_background.png",start_button,end_button);
	
	int menu_option = -1;
	
    while (!WindowShouldClose() && menu_option != game_menu.end) {

		

        
		
        BeginDrawing();
		if(menu_option == -1){
			ClearBackground(GRAY);
			game_menu.display_menu();
			menu_option = game_menu.check_buttons();
		}
		
		if(menu_option == game_menu.start){
			ClearBackground(GRAY);
			world_map.draw_map();
		}else if(menu_option == game_menu.end){

			menu_option = game_menu.end;
		}

        EndDrawing();
	}

	
	

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
