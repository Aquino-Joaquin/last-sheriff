#include "Robot.h"

// Constructor: initializes robot life and loads its texture from the given path
Robot::Robot(int life_robot, const char* skin_path, int positionX, int positionY) {
    this->life = life_robot;
    this->skin = LoadTexture(skin_path);
    position.x = positionX;
    position.y = positionY;
}

// Getter for the robot's life
int Robot::get_life() {
    return this->life;
}

// Setter for the robot's life
void Robot::set_life(int new_life) {
    this->life = new_life;
}

// Draws the robot texture at the specified screen position
void Robot::draw(Vector2 position) {
    DrawTextureV(skin, position, WHITE);
}
