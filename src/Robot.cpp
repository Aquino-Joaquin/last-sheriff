#include "Robot.h"

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
void Robot::draw_on_map(Vector2 position,Map& world_map) {
    Vector2 map_position = world_map.world_to_screen(position.x,position.y);
    DrawTextureV(skin, map_position, WHITE);
}
Rectangle Robot::getRectangle(Map& world_map) {
    Vector2 screenPos = world_map.world_to_screen(position.x, position.y);
    return Rectangle{screenPos.x, screenPos.y, static_cast<float>(skin.width), static_cast<float>(skin.height)};
}

Vector2 Robot::get_position(){
    return position;
}
bool Robot::check_collision(Robot& my_robot,Map& world_map){
    return CheckCollisionRecs(getRectangle(world_map),my_robot.getRectangle(world_map));
}