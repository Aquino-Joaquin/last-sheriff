#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(const char* background_path,  Button& start_button,  Button& end_button)
    : start_button(start_button), end_button(end_button)
{
    background = LoadTexture(background_path);
}
//draw the menu
void Menu::display_menu(){
    DrawTexture(background,0,0,WHITE);
    start_button.draw();
    end_button.draw();

}
//Check if the button is pressed
int Menu::check_buttons(){
    Vector2 mouse_position = GetMousePosition();
    bool mouse_pressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    
    if(start_button.is_pressed(mouse_position,mouse_pressed)){
        return start;
    }
    if(end_button.is_pressed(mouse_position,mouse_pressed)){
        return end;
    }
    return -1;
}
