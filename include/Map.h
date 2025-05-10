#pragma once
#include "raylib.h"
#include "Tile.h"
#include <vector>
class Map{
    private:
        
        struct Matrix2x2
        {
            float m00 , m01;
            float m10 , m11;
        };

    public:
        std::vector<Tile> walkable_tiles;
        std::vector<Tile> no_walkable_tiles;
        std::vector<Tile> borders_tiles;
        Map();
        static Vector2 world_to_screen(float x, float y);
        
        void init_map();
        void draw_map();

        bool is_within_bounds(Vector2 screePos);
        bool is_walkable(Rectangle screenPos);

        
};