#include "Robot.h"
#include <iostream>
using namespace std;

// Default constructor
Robot::Robot() {}

// Constructor with parameters
Robot::Robot(int life_robot, Vector2 position, Animation skin_animated,Rectangle hitBox)
    : skin_animated(skin_animated) {
    this->life = life_robot;
    this->max_life = life_robot;
    this->position = position;

    // Definí el área útil del sprite (ajustá según tu sprite)
    this->hitboxOffset = hitBox; // (x, y, width, height)
}

// Getter for robot's life
int Robot::get_life() {
    return this->life;
}

// Setter for robot's life
void Robot::set_life(int new_life) {
    this->life = new_life;
}

// Get world position of the robot
Vector2 Robot::get_position() {
    return position;
}

// Check if robot is alive
bool Robot::is_alive() {
    return get_life() > 0;
}

// Draws the robot and its life bar
void Robot::draw_on_map() {
    if (!alive) return;

    Vector2 map_position = Map::world_to_screen(position.x, position.y);

    // Draw the animated skin
    skin_animated.animate(map_position, animation_direction, moving, attack_action);

    // === Barra de vida ===
    float bar_width = hitboxOffset.width;
    float bar_height = 5.0f;
    float padding = 4.0f;

    float life_percent = (float)life / (float)max_life;
    if (life_percent < 0) life_percent = 0;

    Vector2 bar_position = {
        map_position.x + hitboxOffset.x,
        map_position.y + hitboxOffset.y - bar_height - padding
    };

    // Background bar
    DrawRectangle(bar_position.x, bar_position.y, bar_width, bar_height, DARKGRAY);

    // Life color
    Color bar_color = (life_percent > 0.5f) ? GREEN :
                      (life_percent > 0.25f) ? ORANGE : RED;

    // Foreground life
    DrawRectangle(bar_position.x, bar_position.y, bar_width * life_percent, bar_height, bar_color);

    // hitbox for debugging
    Rectangle screenHitbox = {
        map_position.x + hitboxOffset.x,
        map_position.y + hitboxOffset.y,
        hitboxOffset.width,
        hitboxOffset.height
    };
    DrawRectangleLinesEx(screenHitbox, 1.0f, RED);
}

// Get screen rectangle for collision
Rectangle Robot::getRectangle() {
    Vector2 screenPos = Map::world_to_screen(position.x, position.y);
    return Rectangle{
        screenPos.x + hitboxOffset.x,
        screenPos.y + hitboxOffset.y,
        hitboxOffset.width,
        hitboxOffset.height
    };
}

// Get screen rectangle at given position
Rectangle Robot::getRectangleAt(float x, float y){
    Vector2 screenPos = Map::world_to_screen(x, y);
    return Rectangle{
        screenPos.x + hitboxOffset.x,
        screenPos.y + hitboxOffset.y,
        hitboxOffset.width,
        hitboxOffset.height
    };
}

// Optional: world-space collision box (útil si usás lógica basada en mundo)
Rectangle Robot::getCollisionBox() {
    return Rectangle{
        position.x + hitboxOffset.x,
        position.y + hitboxOffset.y,
        hitboxOffset.width,
        hitboxOffset.height
    };
}

// Check collision with another robot
bool Robot::check_collision(Robot& my_robot) {
    return CheckCollisionRecs(getRectangle(), my_robot.getRectangle());
}
