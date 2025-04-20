

#include "raylib.h"
#include "Map.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include <iostream>






int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(1280, 720, "Game Project");
	SetTargetFPS(60);

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");



	// Load a texture from the resources directory
	Texture2D playerTexture = LoadTexture("wabbit_alpha.png");
	


	
	//player sprite

	Map world_map(20,20);
	
	
    while (!WindowShouldClose()) {
        
		
        BeginDrawing();
        ClearBackground(GRAY);

		
		
        // Dibujar el mapa
        world_map.draw_map();
		// Draws the player
        //Vector2 playerPos = WorldToScreen(player.destRectangle.x, player.destRectangle.y, transform);
		//doesnt work for now
		//movePlayer(&player,playerPos);

		//DrawTexturePro(player.texture, {0, 0, (float)player.texture.width, (float)player.texture.height}, player.destRectangle, {0, 0}, 0.0f, WHITE);




		
        
        


        EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(playerTexture);

	

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
