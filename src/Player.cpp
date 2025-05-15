#include "Player.h"
#include <iostream>
#include <math.h>
using namespace std;

// Constructor: initializes player life and texture using base Robot constructor,
// and sets the initial player position on the map

Player::Player(){

}
Player::Player(int player_life,Vector2 position,Animation skin_animated,Rectangle hitbox)
    : Robot(player_life,position,skin_animated,hitbox){
        animation_direction = 4;
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
        bool moved = false;
        Vector2 direction = { 0, 0 };

        if (IsKeyPressed(KEY_SPACE) && !attack_action) {
            attack_action = true;
            moving = false;

            animation_direction = last_direction == 1 ? 2 :
                                  last_direction == 2 ? 6 :
                                  last_direction == 3 ? 8 :
                                  last_direction == 4 ? 4 : 4;
        }

        if (!attack_action) {
            if (IsKeyDown(KEY_W)) {
                direction.y -= 1;
                last_direction = 4;
                animation_direction = 4;
                moving = true;
                moved = true;
            } else if (IsKeyDown(KEY_S)) {
                direction.y += 1;
                last_direction = 3;
                animation_direction = 8;
                moving = true;
                moved = true;
            } else if (IsKeyDown(KEY_D)) {
                direction.x += 1;
                last_direction = 1;
                animation_direction = 2;
                moving = true;
                moved = true;
            } else if (IsKeyDown(KEY_A)) {
                direction.x -= 1;
                last_direction = 2;
                animation_direction = 6;
                moving = true;
                moved = true;
            } else {
                moving = false;
            }
        } else {
            moving = false;
        }

        if (moved) {
            newX += direction.x * 0.1f;
            newY += direction.y * 0.1f;

            Rectangle newRect = getRectangleAt(newX, newY);
            if (world_map.is_walkable(newRect)) {
                position.x = newX;
                position.y = newY;
                lastMoveTime = currentTime;
            }
        }
    }

    if (attack_action && skin_animated.isAttackFinished()) {
        attack_action = false;
    }
}