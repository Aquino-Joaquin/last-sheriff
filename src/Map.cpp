#include "Map.h"
#include <iostream>
using namespace std;
Map::Map(int map_width,int map_height){
    this->width = map_width;
    this->height = map_height;
}
void Map::draw_tile(Vector2 center,int map_height, Color topColor){
    int h = map_height * TILE_HEIGHT;
        
    // Top
    Vector2 top    = { center.x, center.y - h };
    Vector2 right  = { center.x + TILE_WIDTH / 2, center.y + TILE_HEIGHT / 2 - h };
    Vector2 bottom = { center.x, center.y + TILE_HEIGHT - h };
    Vector2 left   = { center.x - TILE_WIDTH / 2, center.y + TILE_HEIGHT / 2 - h };

    //draw the top face
    DrawTriangle(top, bottom, right, topColor);
    DrawTriangle(bottom, top, left, topColor);


    Vector2 r1 = right;
    Vector2 r2 = { right.x, right.y + h };
    Vector2 b1 = bottom;
    Vector2 b2 = { bottom.x, bottom.y + h };

    DrawTriangle(r1, b1, r2, topColor);
    DrawTriangle(r2, b1, b2, topColor);


    Vector2 l1 = left;
    Vector2 l2 = { left.x, left.y + h };

    DrawTriangle(l1, l2, b1, topColor);
    DrawTriangle(l2, b2, b1, topColor);

    // draw the edge
    DrawLineV(top, right, DARKGRAY);
    DrawLineV(right, bottom, DARKGRAY);
    DrawLineV(bottom, left, DARKGRAY);
    DrawLineV(left, top, DARKGRAY);
}
//apply the transformation 
Vector2 Map::world_to_screen(int x, int y){
    Matrix2x2 transform = {
        static_cast<float>(0.5 * TILE_WIDTH), static_cast<float>(-0.5 * TILE_WIDTH),
        static_cast<float>(0.5 * TILE_HEIGHT), static_cast<float>(0.5 * TILE_HEIGHT)
    };
    return {
        static_cast<float>(x * transform.m00 + y * transform.m01) + GetScreenWidth()/2,  
        static_cast<float>(x * transform.m10 + y * transform.m11) + GetScreenHeight()/10   
    };
}
//draw the map
void Map::draw_map(){
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Vector2 screenPos = world_to_screen(x, y);
            //cout<<"x : "<<screenPos.x<<" y : "<<screenPos.y<<endl;
            int tileHeight = 1;
            draw_tile(screenPos, tileHeight, BLACK);
            
        }
    }
    
}
bool Map::is_within_bounds(int x, int y) {
    return x >= 0 && x < (width -2)  && y >= 0 && y < (height-2);
}



        