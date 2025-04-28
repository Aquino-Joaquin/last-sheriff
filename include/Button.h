#pragma once
#include "raylib.h"
class Button{
    private:
        Vector2 position;
        Texture2D texture;
    public:
        
        Button(const char* image_path, Vector2 image_position);
        
        void draw();

        bool is_pressed(Vector2 mouse_position, bool mouse_pressed);

        


};