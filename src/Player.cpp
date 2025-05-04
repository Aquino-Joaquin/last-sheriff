#include "Player.h"
#include <iostream>
using namespace std;

// Constructor: initializes player life and texture using base Robot constructor,
// and sets the initial player position on the map
Player::Player(int player_life, const char* skin_path, int pos_x, int pos_y)
    : Robot(player_life, skin_path) {
    playerX = pos_x;
    playerY = pos_y;
}

// Cooldown values for controlling player movement speed
float moveCooldown = 0.2f;   // Minimum time between moves
float lastMoveTime = 0.0f;   // Time of the last movement

// Moves the player if movement keys are pressed and cooldown allows it
void Player::move_player(Map& world_map) {
    int newX = playerX;
    int newY = playerY;

    float currentTime = GetTime();

    // Movement input is only processed if enough time has passed since the last move
    if (currentTime - lastMoveTime >= moveCooldown) {
        if (IsKeyDown(KEY_W)) { newY -= 1; lastMoveTime = currentTime; }
        else if (IsKeyDown(KEY_S)) { newY += 1; lastMoveTime = currentTime; }
        else if (IsKeyDown(KEY_D)) { newX += 1; lastMoveTime = currentTime; }
        else if (IsKeyDown(KEY_A)) { newX -= 1; lastMoveTime = currentTime; }

        // Only update player position if new coordinates are within bounds
        if (world_map.is_within_bounds(newX, newY)) {
            playerX = newX;
            playerY = newY;
        }
    }

    // Convert world position to screen coordinates and draw the player
    Vector2 player_map_position = world_map.world_to_screen(playerX, playerY);
    DrawTexture(skin, player_map_position.x, player_map_position.y, WHITE);
}
