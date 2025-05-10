#pragma once
#include "Button.h"

class Menu{
    private:
        Texture2D background;
        Button start_button;
        Button end_button;
        
    public:
        static constexpr int start = 0;
        static constexpr int end = 1;
        static constexpr int retry =2;
        Menu();
        Menu(const char* background_path, Button start_button, Button end_button);
        void display_menu();
        int check_buttons();
        


};