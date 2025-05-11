#pragma once
#include "Button.h"

class Menu{
    private:
        Texture2D background;
        Button start_button;
        Button end_button;
        
        
    public:
        Sound menu_sound;
        static constexpr int start = 0;
        static constexpr int end = 1;
        static constexpr int retry =2;
        Menu();
        Menu(const char* background_path,const char* menu_sound_path ,Button start_button, Button end_button);
        void display_menu();
        int check_buttons();
        


};