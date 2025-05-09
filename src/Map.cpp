#include "Map.h"
#include <iostream>
#include "raylib.h"
#include "rlgl.h"
using namespace std;

// Constructor: sets the map's width and height
Map::Map() {
    
}

// Converts world coordinates (x, y) to screen coordinates using isometric transformation
Vector2 Map::world_to_screen(float x, float y) {
    Matrix2x2 transform = {
        static_cast<float>(0.5 * 64), static_cast<float>(-0.5 * 64),
        static_cast<float>(0.5 * 32), static_cast<float>(0.5 * 32)
    };

    return {
        static_cast<float>(x * transform.m00 + y * transform.m01) ,
        static_cast<float>(x * transform.m10 + y * transform.m11) 
    };
}

// Draws the entire map as a grid of tiles
void Map::draw_map() {
    borders_tiles.push_back(Tile({15,5},1,GRAY,false));
    //walkable_tiles.push_back(Tile({15,5},1,GRAY,true));
    for(auto& tile:walkable_tiles){
        tile.draw();
    }
    for(auto& tile:no_walkable_tiles){
        tile.draw();
    }
    for(auto& tile:borders_tiles){
        tile.drawCollisionEdges();
    }

}

bool Map::is_walkable(Rectangle screenPos) {
    for(auto& tile:no_walkable_tiles){
        bool collision = tile.checkRectangleLineCollision(screenPos,tile.collisionEdges);
        if(collision){
            return false;
        }
    }
    for(auto& tile:borders_tiles){
        bool collision = tile.checkRectangleLineCollision(screenPos,tile.collisionEdges);
        if(collision){
            return false;
        }
    }
    return true;
}
