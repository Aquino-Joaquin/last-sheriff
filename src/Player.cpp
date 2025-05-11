#include "Player.h"
#include <iostream>
using namespace std;

// Constructor: initializes player life and texture using base Robot constructor,
// and sets the initial player position on the map

Player::Player(){

}
Player::Player(int player_life, const char* skin_path, Vector2 position)
    : Robot(player_life, skin_path,position){
    }   

// Cooldown values for controlling player movement speed
float moveCooldown = 0.001;   // Minimum time between moves
float lastMoveTime = 0.0f;   // Time of the last movement

// Moves the player if movement keys are pressed and cooldown allows it
void Player::move_player(Map& world_map) {
    float newX = position.x;
    float newY = position.y;

    float currentTime = GetTime();

    if (currentTime - lastMoveTime >= moveCooldown) {
        if (IsKeyDown(KEY_W)) { 
            newY -= 0.1; 
            last_direction = 4; 
            lastMoveTime = currentTime; 
        }
        else if (IsKeyDown(KEY_S)) { 
            newY += 0.1; 
            last_direction = 3; 
            lastMoveTime = currentTime; 
        }
        else if (IsKeyDown(KEY_D)) { 
            newX += 0.1; 
            last_direction = 1; 
            lastMoveTime = currentTime; 
        }
        else if (IsKeyDown(KEY_A)) { 
            newX -= 0.1; 
            last_direction = 2; 
            lastMoveTime = currentTime; 
        }

        Rectangle newRect = getRectangleAt(newX, newY);

        if (world_map.is_walkable(newRect)) {
            position.x = newX;
            position.y = newY;
        }
    }
}
