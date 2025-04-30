#pragma once
#include "raylib.h"
class Robot{
    private:
        int life;
    protected:
        Texture2D skin;
        int get_life();
        void set_life(int life);
        
    public:
        Robot(int life, const char* skin_path);
        void draw(Vector2 position);
        // ~Robot();

};