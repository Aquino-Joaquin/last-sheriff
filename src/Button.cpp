#include "Button.h"

//Constructor
Button::Button(const char* image_path,Vector2 image_position){

    texture = LoadTexture(image_path);
    

    this->position = image_position;


}
//Draw method const(button dont change)
void Button::draw() {
    DrawTextureV(texture,position,WHITE);
}
//is_pressed method const(button dont change)
bool Button::is_pressed(Vector2 mouse_position, bool mouse_pressed) 
{
    Rectangle rect = {position.x,position.y,static_cast<float>(texture.width),static_cast<float>(texture.height)};

    if(CheckCollisionPointRec(mouse_position,rect) && mouse_pressed){
        return true;
    }

    return false;
}

        