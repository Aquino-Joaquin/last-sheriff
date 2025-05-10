#include "Robot.h"
#include <iostream>
using namespace std;
Robot::Robot(){
    
}
// Constructor: initializes robot life and loads its texture from the given path
Robot::Robot(int life_robot, const char* skin_path, Vector2 position) {
    this->life = life_robot;
    this->skin = LoadTexture(skin_path);
    this->position = position;
    
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
void Robot::draw_on_map() {
    if(alive){
        Vector2 map_position = Map::world_to_screen(position.x,position.y);
        DrawTextureV(skin, map_position, WHITE);
    }
    
}
Rectangle Robot::getRectangle() {
    Vector2 screenPos = Map::world_to_screen(position.x, position.y);
    return Rectangle{screenPos.x, screenPos.y, static_cast<float>(skin.width), static_cast<float>(skin.height)};
}
Rectangle Robot::getRectangleAt(float x, float y){
    Vector2 screenPos = Map::world_to_screen(x,y);
    return Rectangle{screenPos.x , screenPos.y, static_cast<float>(skin.width), static_cast<float>(skin.height)};
}

Vector2 Robot::get_position(){
    return position;
}
bool Robot::check_collision(Robot& my_robot){
    return CheckCollisionRecs(getRectangle(),my_robot.getRectangle());
}
bool Robot::check_alive(){
    if(get_life() <= 0){
        alive = false;
    }
    return alive;
}