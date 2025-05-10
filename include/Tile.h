#pragma once
#include "raylib.h"
#include <vector>
#include <utility> 
class Tile{
    public:
        Tile(Vector2 position, float altura, Color sidesColor);
        void draw();
        void drawCollisionEdges();
        bool checkRectangleLineCollision(Rectangle rect, const std::vector<std::pair<Vector2, Vector2>>& lines);

        std::vector<std::pair<Vector2, Vector2>> collisionEdges;
        Vector2 position;
        float tile_width = 64;
        float tile_height = 32;
        float depth;
        private:
        Color sideColor;

};