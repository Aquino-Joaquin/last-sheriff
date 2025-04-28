#include "Robot.h"

Robot::Robot(int life, const char* skin_path){
    this->life = life;
    this->skin = LoadTexture(skin_path);
}
int Robot::get_life(){
    return this->life;
}
void Robot::set_life(int life){
    this->life = life;
}
void Robot::draw(Vector2 position){
    DrawTextureV(skin,position,WHITE);
}
Robot::~Robot(){
    UnloadTexture(skin);
}