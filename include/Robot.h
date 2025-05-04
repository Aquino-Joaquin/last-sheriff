#pragma once
#include "raylib.h"
class Robot{
    private:
        int life;
    protected:
        Texture2D skin;
        Vector2 position;
        int get_life();
        void set_life(int life);
        
    public:
        Robot(int life, const char* skin_path,int positionX, int positionY);
        void draw(Vector2 position);
        // ~Robot();

};