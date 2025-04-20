#pragma once
#include "raylib.h"
class Map{
    private:
        const int TILE_WIDTH = 64;
        const int TILE_HEIGHT = 32;
        int width;
        int height;
        struct Matrix2x2
        {
            float m00 , m01;
            float m10 , m11;
        };

    public:
        Map(int width, int height);
        
        void draw_tile(Vector2 center,int height, Color topColor);

        Vector2 world_to_screen(int x, int y);
        
        void draw_map();
};