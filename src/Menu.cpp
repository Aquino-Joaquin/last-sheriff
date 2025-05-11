#include "Menu.h"
#include <iostream>
using namespace std;
Menu::Menu(){
    
}
// Constructor: loads background texture and stores references to the start and end buttons
Menu::Menu(const char* background_path,const char* menu_sound_path ,Button start_button, Button end_button)
    : start_button(start_button), end_button(end_button)
{
    background = LoadTexture(background_path);
    menu_sound = LoadSound(menu_sound_path);
}

// Draws the menu background and both buttons
void Menu::display_menu() {
    if(!IsSoundPlaying(menu_sound)){
        PlaySound(menu_sound);
    }
    DrawTexture(background, 0, 0, WHITE);
    start_button.draw();
    end_button.draw();
}

// Checks if either button is pressed and returns a corresponding value
int Menu::check_buttons() {
    Vector2 mouse_position = GetMousePosition();
    bool mouse_pressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

    // Return a constant if start button is pressed
    if (start_button.is_pressed(mouse_position, mouse_pressed)) {
        return start;
    }

    // Return a different constant if end button is pressed
    if (end_button.is_pressed(mouse_position, mouse_pressed)) {
        return end;
    }

    // Return -1 if no button is pressed
    return -1;
}
