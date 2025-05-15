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

void Map::init_map() {
    walkable_tiles.push_back(Tile({5,0},1,GRAY));
    walkable_tiles.push_back(Tile({6,0},1,GRAY));
    walkable_tiles.push_back(Tile({7,0},1,GRAY));
    walkable_tiles.push_back(Tile({8,0},1,GRAY));
    walkable_tiles.push_back(Tile({9,0},1,GRAY));
    walkable_tiles.push_back(Tile({10,0},1,GRAY));
    walkable_tiles.push_back(Tile({11,0},1,GRAY));
    walkable_tiles.push_back(Tile({12,0},1,GRAY));
    walkable_tiles.push_back(Tile({13,0},1,GRAY));  
    walkable_tiles.push_back(Tile({14,0},1,GRAY));
    walkable_tiles.push_back(Tile({15,0},1,GRAY));
    walkable_tiles.push_back(Tile({16,0},1,GRAY));
    walkable_tiles.push_back(Tile({17,0},1,GRAY));
    walkable_tiles.push_back(Tile({18,0},1,GRAY));
    walkable_tiles.push_back(Tile({19,0},1,GRAY));
    walkable_tiles.push_back(Tile({20,0},1,GRAY));
    walkable_tiles.push_back(Tile({21,0},1,GRAY));
    walkable_tiles.push_back(Tile({22,0},1,GRAY));
    walkable_tiles.push_back(Tile({23,0},1,GRAY));
    walkable_tiles.push_back(Tile({24,0},1,GRAY));
    walkable_tiles.push_back(Tile({25,0},1,GRAY));
    walkable_tiles.push_back(Tile({26,0},1,GRAY));
    walkable_tiles.push_back(Tile({27,0},1,GRAY));
    walkable_tiles.push_back(Tile({28,0},1,GRAY));
    walkable_tiles.push_back(Tile({29,0},1,GRAY));
    walkable_tiles.push_back(Tile({30,0},1,GRAY));
    walkable_tiles.push_back(Tile({31,0},1,GRAY));
    walkable_tiles.push_back(Tile({32,0},1,GRAY));
    walkable_tiles.push_back(Tile({33,0},1,GRAY));
    walkable_tiles.push_back(Tile({34,0},1,GRAY));
    walkable_tiles.push_back(Tile({35,0},1,GRAY));
    walkable_tiles.push_back(Tile({36,0},1,GRAY));
    walkable_tiles.push_back(Tile({37,0},1,GRAY));
    walkable_tiles.push_back(Tile({38,0},1,GRAY));
    walkable_tiles.push_back(Tile({39,0},1,GRAY));

    walkable_tiles.push_back(Tile({13,1},1,GRAY));
    walkable_tiles.push_back(Tile({14,1},1,GRAY));
    walkable_tiles.push_back(Tile({15,1},1,GRAY));
    walkable_tiles.push_back(Tile({16,1},1,GRAY));
    walkable_tiles.push_back(Tile({17,1},1,GRAY));
    walkable_tiles.push_back(Tile({18,1},1,GRAY));
    walkable_tiles.push_back(Tile({19,1},1,GRAY));
    walkable_tiles.push_back(Tile({20,1},1,GRAY));
    walkable_tiles.push_back(Tile({21,1},1,GRAY));
    walkable_tiles.push_back(Tile({22,1},1,GRAY));
    walkable_tiles.push_back(Tile({23,1},1,GRAY));
    walkable_tiles.push_back(Tile({24,1},1,GRAY));
    walkable_tiles.push_back(Tile({25,1},1,GRAY));
    walkable_tiles.push_back(Tile({26,1},1,GRAY));
    walkable_tiles.push_back(Tile({27,1},1,GRAY));
    walkable_tiles.push_back(Tile({28,1},1,GRAY));
    walkable_tiles.push_back(Tile({29,1},1,GRAY));

    walkable_tiles.push_back(Tile({13,2},7,GRAY));
    walkable_tiles.push_back(Tile({14,2},1,GRAY));
    walkable_tiles.push_back(Tile({15,2},1,GRAY));
    walkable_tiles.push_back(Tile({16,2},1,GRAY));
    walkable_tiles.push_back(Tile({17,2},1,GRAY));
    walkable_tiles.push_back(Tile({18,2},1,GRAY));
    walkable_tiles.push_back(Tile({19,2},1,GRAY));
    walkable_tiles.push_back(Tile({20,2},1,GRAY));
    walkable_tiles.push_back(Tile({21,2},1,GRAY));
    walkable_tiles.push_back(Tile({22,2},1,GRAY));
    walkable_tiles.push_back(Tile({23,2},1,GRAY));
    walkable_tiles.push_back(Tile({24,2},1,GRAY));
    walkable_tiles.push_back(Tile({25,2},1,GRAY));
    walkable_tiles.push_back(Tile({26,2},1,GRAY));
    walkable_tiles.push_back(Tile({27,2},1,GRAY));
    walkable_tiles.push_back(Tile({28,2},1,GRAY));
    walkable_tiles.push_back(Tile({29,2},1,GRAY));

    walkable_tiles.push_back(Tile({13,3},7,GRAY));
    walkable_tiles.push_back(Tile({14,3},1,GRAY));
    walkable_tiles.push_back(Tile({15,3},1,GRAY));
    walkable_tiles.push_back(Tile({16,3},1,GRAY));
    walkable_tiles.push_back(Tile({17,3},1,GRAY));
    walkable_tiles.push_back(Tile({18,3},1,GRAY));
    walkable_tiles.push_back(Tile({19,3},1,GRAY));
    walkable_tiles.push_back(Tile({20,3},1,GRAY));
    walkable_tiles.push_back(Tile({21,3},1,GRAY));
    walkable_tiles.push_back(Tile({22,3},1,GRAY));
    walkable_tiles.push_back(Tile({23,3},1,GRAY));
    walkable_tiles.push_back(Tile({24,3},1,GRAY));
    walkable_tiles.push_back(Tile({25,3},1,GRAY));
    walkable_tiles.push_back(Tile({26,3},1,GRAY));
    walkable_tiles.push_back(Tile({27,3},1,GRAY));
    walkable_tiles.push_back(Tile({28,3},1,GRAY));
    walkable_tiles.push_back(Tile({29,3},1,GRAY));

    walkable_tiles.push_back(Tile({13,4},7,GRAY));
    walkable_tiles.push_back(Tile({14,4},1,GRAY));
    walkable_tiles.push_back(Tile({15,4},1,GRAY));
    walkable_tiles.push_back(Tile({16,4},1,GRAY));
    walkable_tiles.push_back(Tile({17,4},1,GRAY));
    walkable_tiles.push_back(Tile({18,4},1,GRAY));
    walkable_tiles.push_back(Tile({19,4},1,GRAY));
    walkable_tiles.push_back(Tile({20,4},1,GRAY));
    walkable_tiles.push_back(Tile({21,4},1,GRAY));
    walkable_tiles.push_back(Tile({22,4},1,GRAY));
    walkable_tiles.push_back(Tile({23,4},1,GRAY));
    walkable_tiles.push_back(Tile({24,4},1,GRAY));
    walkable_tiles.push_back(Tile({25,4},1,GRAY));
    walkable_tiles.push_back(Tile({26,4},1,GRAY));
    walkable_tiles.push_back(Tile({27,4},1,GRAY));
    walkable_tiles.push_back(Tile({28,4},1,GRAY));
    walkable_tiles.push_back(Tile({29,4},1,GRAY));

    walkable_tiles.push_back(Tile({13,5},7,GRAY));
    walkable_tiles.push_back(Tile({14,5},1,GRAY));
    walkable_tiles.push_back(Tile({15,5},1,GRAY));
    walkable_tiles.push_back(Tile({16,5},1,GRAY));
    walkable_tiles.push_back(Tile({17,5},1,GRAY));
    walkable_tiles.push_back(Tile({18,5},1,GRAY));
    walkable_tiles.push_back(Tile({19,5},1,GRAY));
    walkable_tiles.push_back(Tile({20,5},1,GRAY));
    walkable_tiles.push_back(Tile({21,5},1,GRAY));
    walkable_tiles.push_back(Tile({22,5},1,GRAY));
    walkable_tiles.push_back(Tile({23,5},1,GRAY));
    walkable_tiles.push_back(Tile({24,5},1,GRAY));
    walkable_tiles.push_back(Tile({25,5},1,GRAY));
    walkable_tiles.push_back(Tile({26,5},1,GRAY));
    walkable_tiles.push_back(Tile({27,5},1,GRAY));
    walkable_tiles.push_back(Tile({28,5},1,GRAY));
    walkable_tiles.push_back(Tile({29,5},1,GRAY));

    walkable_tiles.push_back(Tile({13,6},7,GRAY));
    walkable_tiles.push_back(Tile({14,6},1,GRAY));
    walkable_tiles.push_back(Tile({15,6},1,GRAY));
    walkable_tiles.push_back(Tile({16,6},1,GRAY));
    walkable_tiles.push_back(Tile({17,6},1,GRAY));
    walkable_tiles.push_back(Tile({18,6},1,GRAY));
    walkable_tiles.push_back(Tile({19,6},1,GRAY));
    walkable_tiles.push_back(Tile({20,6},1,GRAY));
    walkable_tiles.push_back(Tile({21,6},1,GRAY));
    walkable_tiles.push_back(Tile({22,6},1,GRAY));
    walkable_tiles.push_back(Tile({23,6},1,GRAY));
    walkable_tiles.push_back(Tile({24,6},1,GRAY));
    walkable_tiles.push_back(Tile({25,6},1,GRAY));
    walkable_tiles.push_back(Tile({26,6},1,GRAY));
    walkable_tiles.push_back(Tile({27,6},1,GRAY));
    walkable_tiles.push_back(Tile({28,6},1,GRAY));
    walkable_tiles.push_back(Tile({29,6},1,GRAY));

    walkable_tiles.push_back(Tile({13,7},7,GRAY));
    walkable_tiles.push_back(Tile({14,7},1,GRAY));
    walkable_tiles.push_back(Tile({15,7},1,GRAY));
    walkable_tiles.push_back(Tile({16,7},1,GRAY));
    walkable_tiles.push_back(Tile({17,7},1,GRAY));
    walkable_tiles.push_back(Tile({18,7},1,GRAY));
    walkable_tiles.push_back(Tile({19,7},1,GRAY));
    walkable_tiles.push_back(Tile({20,7},1,GRAY));
    walkable_tiles.push_back(Tile({21,7},1,GRAY));
    walkable_tiles.push_back(Tile({22,7},1,GRAY));
    walkable_tiles.push_back(Tile({23,7},1,GRAY));
    walkable_tiles.push_back(Tile({24,7},1,GRAY));
    walkable_tiles.push_back(Tile({25,7},1,GRAY));
    walkable_tiles.push_back(Tile({26,7},1,GRAY));
    walkable_tiles.push_back(Tile({27,7},1,GRAY));
    walkable_tiles.push_back(Tile({28,7},1,GRAY));
    walkable_tiles.push_back(Tile({29,7},1,GRAY));

    walkable_tiles.push_back(Tile({13,8},7,GRAY));
    walkable_tiles.push_back(Tile({14,8},1,GRAY));
    walkable_tiles.push_back(Tile({15,8},1,GRAY));
    walkable_tiles.push_back(Tile({16,8},1,GRAY));
    walkable_tiles.push_back(Tile({17,8},1,GRAY));
    walkable_tiles.push_back(Tile({18,8},1,GRAY));
    walkable_tiles.push_back(Tile({19,8},1,GRAY));
    walkable_tiles.push_back(Tile({20,8},1,GRAY));
    walkable_tiles.push_back(Tile({21,8},1,GRAY));
    walkable_tiles.push_back(Tile({22,8},1,GRAY));
    walkable_tiles.push_back(Tile({23,8},1,GRAY));
    walkable_tiles.push_back(Tile({24,8},1,GRAY));
    walkable_tiles.push_back(Tile({25,8},1,GRAY));
    walkable_tiles.push_back(Tile({26,8},1,GRAY));
    walkable_tiles.push_back(Tile({27,8},1,GRAY));
    walkable_tiles.push_back(Tile({28,8},1,GRAY));
    walkable_tiles.push_back(Tile({29,8},1,GRAY));

    walkable_tiles.push_back(Tile({13,9},7,GRAY));
    walkable_tiles.push_back(Tile({14,9},1,GRAY));
    walkable_tiles.push_back(Tile({15,9},1,GRAY));
    walkable_tiles.push_back(Tile({16,9},1,GRAY));
    walkable_tiles.push_back(Tile({17,9},1,GRAY));
    walkable_tiles.push_back(Tile({18,9},1,GRAY));
    walkable_tiles.push_back(Tile({19,9},1,GRAY));
    walkable_tiles.push_back(Tile({20,9},1,GRAY));
    walkable_tiles.push_back(Tile({21,9},1,GRAY));
    walkable_tiles.push_back(Tile({22,9},1,GRAY));
    walkable_tiles.push_back(Tile({23,9},1,GRAY));
    walkable_tiles.push_back(Tile({24,9},1,GRAY));
    walkable_tiles.push_back(Tile({25,9},1,GRAY));
    walkable_tiles.push_back(Tile({26,9},1,GRAY));
    walkable_tiles.push_back(Tile({27,9},1,GRAY));
    walkable_tiles.push_back(Tile({28,9},1,GRAY));
    walkable_tiles.push_back(Tile({29,9},1,GRAY));

    walkable_tiles.push_back(Tile({13,10},7,GRAY));
    walkable_tiles.push_back(Tile({14,10},1,GRAY));
    walkable_tiles.push_back(Tile({15,10},1,GRAY));
    walkable_tiles.push_back(Tile({16,10},1,GRAY));
    walkable_tiles.push_back(Tile({17,10},1,GRAY));
    walkable_tiles.push_back(Tile({18,10},1,GRAY));
    walkable_tiles.push_back(Tile({19,10},1,GRAY));
    walkable_tiles.push_back(Tile({20,10},1,GRAY));
    walkable_tiles.push_back(Tile({21,10},1,GRAY));
    walkable_tiles.push_back(Tile({22,10},1,GRAY));
    walkable_tiles.push_back(Tile({23,10},1,GRAY));
    walkable_tiles.push_back(Tile({24,10},1,GRAY));
    walkable_tiles.push_back(Tile({25,10},1,GRAY));
    walkable_tiles.push_back(Tile({26,10},1,GRAY));
    walkable_tiles.push_back(Tile({27,10},1,GRAY));
    walkable_tiles.push_back(Tile({28,10},1,GRAY));
    walkable_tiles.push_back(Tile({29,10},1,GRAY));

    walkable_tiles.push_back(Tile({13,11},7,GRAY));
    walkable_tiles.push_back(Tile({14,11},1,GRAY));
    walkable_tiles.push_back(Tile({15,11},1,GRAY));
    walkable_tiles.push_back(Tile({16,11},1,GRAY));
    walkable_tiles.push_back(Tile({17,11},1,GRAY));
    walkable_tiles.push_back(Tile({18,11},1,GRAY));
    walkable_tiles.push_back(Tile({19,11},1,GRAY));
    walkable_tiles.push_back(Tile({20,11},1,GRAY));
    walkable_tiles.push_back(Tile({21,11},1,GRAY));
    walkable_tiles.push_back(Tile({22,11},1,GRAY));
    walkable_tiles.push_back(Tile({23,11},1,GRAY));
    walkable_tiles.push_back(Tile({24,11},1,GRAY));
    walkable_tiles.push_back(Tile({25,11},1,GRAY));
    walkable_tiles.push_back(Tile({26,11},1,GRAY));
    walkable_tiles.push_back(Tile({27,11},1,GRAY));
    walkable_tiles.push_back(Tile({28,11},1,GRAY));
    walkable_tiles.push_back(Tile({29,11},1,GRAY));

    walkable_tiles.push_back(Tile({13,12},7,GRAY));
    walkable_tiles.push_back(Tile({14,12},1,GRAY));
    walkable_tiles.push_back(Tile({15,12},1,GRAY));
    walkable_tiles.push_back(Tile({16,12},1,GRAY));
    walkable_tiles.push_back(Tile({17,12},1,GRAY));
    walkable_tiles.push_back(Tile({18,12},1,GRAY));
    walkable_tiles.push_back(Tile({19,12},1,GRAY));
    walkable_tiles.push_back(Tile({20,12},1,GRAY));
    walkable_tiles.push_back(Tile({21,12},1,GRAY));
    walkable_tiles.push_back(Tile({22,12},1,GRAY));
    walkable_tiles.push_back(Tile({23,12},1,GRAY));
    walkable_tiles.push_back(Tile({24,12},1,GRAY));
    walkable_tiles.push_back(Tile({25,12},1,GRAY));
    walkable_tiles.push_back(Tile({26,12},1,GRAY));
    walkable_tiles.push_back(Tile({27,12},1,GRAY));
    walkable_tiles.push_back(Tile({28,12},1,GRAY));
    walkable_tiles.push_back(Tile({29,12},1,GRAY));

    // borders_tiles.push_back(Tile({13,12},1,GRAY));
    // borders_tiles.push_back(Tile({13,11},1,GRAY));
    // borders_tiles.push_back(Tile({13,10},1,GRAY));
    // borders_tiles.push_back(Tile({13,9},1,GRAY));
    // borders_tiles.push_back(Tile({13,8},1,GRAY));
    // borders_tiles.push_back(Tile({13,7},1,GRAY));
    // borders_tiles.push_back(Tile({13,6},1,GRAY));
    // borders_tiles.push_back(Tile({13,5},1,GRAY));
    // borders_tiles.push_back(Tile({13,4},1,GRAY));
    // borders_tiles.push_back(Tile({13,3},1,GRAY));
    // borders_tiles.push_back(Tile({13,2},1,GRAY));
    // borders_tiles.push_back(Tile({13,1},1,GRAY));
    

}

// Draws the entire map as a grid of tiles
void Map::draw_map() {
    
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
