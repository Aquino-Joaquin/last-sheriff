#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(int player_life, const char* skin_path,int pos_x,int pos_y) : Robot(player_life,skin_path){
    playerX = pos_x;
    playerY = pos_y;
}

float moveCooldown = 0.2f;   
float lastMoveTime = 0.0f;
// Move the player on the map
void Player::move_player(Map& world_map){
    int newX = playerX;
    int newY = playerY;

    float currentTime = GetTime();
    //Delay in order to move slower 
    if (currentTime - lastMoveTime >= moveCooldown) {
        if (IsKeyDown(KEY_W)) { newY -= 1; lastMoveTime = currentTime; }
        else if (IsKeyDown(KEY_S)) { newY += 1; lastMoveTime = currentTime; }
        else if (IsKeyDown(KEY_D)) { newX += 1; lastMoveTime = currentTime; }
        else if (IsKeyDown(KEY_A)) { newX -= 1; lastMoveTime = currentTime; }

        if (world_map.is_within_bounds(newX, newY)) {
            playerX = newX;
            playerY = newY;
        }
    }

    Vector2 player_map_position = world_map.world_to_screen(playerX, playerY);


    DrawTexture(skin, player_map_position.x, player_map_position.y, WHITE);
}
