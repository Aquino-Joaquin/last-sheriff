#include "Robot.h"
#include <iostream>
using namespace std;

// Default constructor
Robot::Robot() {}

// Constructor with parameters
Robot::Robot(int life_robot, const char* skin_path, Vector2 position) {
    this->life = life_robot;
    this->max_life = life_robot;  // Save the initial life as max life
    this->skin = LoadTexture(skin_path);
    this->position = position;
}

// Getter for robot's life
int Robot::get_life() {
    return this->life;
}

// Setter for robot's life
void Robot::set_life(int new_life) {
    this->life = new_life;
}

// Draws the robot and a life bar above it
void Robot::draw_on_map() {
    if (alive) {
        Vector2 map_position = Map::world_to_screen(position.x, position.y);

        // Draw the robot texture
        DrawTextureV(skin, map_position, WHITE);

        // Health bar settings
        float bar_width = static_cast<float>(skin.width); // full width of the robot
        float bar_height = 5.0f;
        float padding = 4.0f; // space between robot and the bar

        float life_percent = (float)life / (float)max_life;
        if (life_percent < 0) life_percent = 0;

        Vector2 bar_position = {
            map_position.x,
            map_position.y - bar_height - padding
        };

        // Background bar
        DrawRectangle(bar_position.x, bar_position.y, bar_width, bar_height, DARKGRAY);

        // Foreground bar color based on health
        Color bar_color = (life_percent > 0.5f) ? GREEN :
                          (life_percent > 0.25f) ? ORANGE : RED;

        // Foreground life bar
        DrawRectangle(bar_position.x, bar_position.y, bar_width * life_percent, bar_height, bar_color);
    }
}

// Returns the screen rectangle of the robot
Rectangle Robot::getRectangle() {
    Vector2 screenPos = Map::world_to_screen(position.x, position.y);
    return Rectangle{screenPos.x, screenPos.y, static_cast<float>(skin.width), static_cast<float>(skin.height)};
}

// Returns the screen rectangle for a given world position
Rectangle Robot::getRectangleAt(float x, float y){
    Vector2 screenPos = Map::world_to_screen(x, y);
    return Rectangle{screenPos.x, screenPos.y, static_cast<float>(skin.width), static_cast<float>(skin.height)};
}

// Get world position of the robot
Vector2 Robot::get_position() {
    return position;
}

// Checks collision with another robot
bool Robot::check_collision(Robot& my_robot) {
    return CheckCollisionRecs(getRectangle(), my_robot.getRectangle());
}

// Checks if the robot is alive
bool Robot::is_alive() {
    return get_life() > 0;
}
