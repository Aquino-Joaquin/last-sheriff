#include "Map.h"

Map::Map(int width,int height){
    this->width = width;
    this->height = height;
}
void Map::draw_tile(Vector2 center,int height, Color topColor){
    int h = height * TILE_HEIGHT;
        
    // Parte superior (rombo clásico elevado)
    Vector2 top    = { center.x, center.y - h };
    Vector2 right  = { center.x + TILE_WIDTH / 2, center.y + TILE_HEIGHT / 2 - h };
    Vector2 bottom = { center.x, center.y + TILE_HEIGHT - h };
    Vector2 left   = { center.x - TILE_WIDTH / 2, center.y + TILE_HEIGHT / 2 - h };

    // Dibujar la cara superior
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

    // Borde (opcional)
    DrawLineV(top, right, DARKGRAY);
    DrawLineV(right, bottom, DARKGRAY);
    DrawLineV(bottom, left, DARKGRAY);
    DrawLineV(left, top, DARKGRAY);
}
Vector2 Map::world_to_screen(int x, int y){
    Matrix2x2 transform = {
        (0.5 * TILE_WIDTH), (-0.5 * TILE_WIDTH),
        (0.5 * TILE_HEIGHT), (0.5 * TILE_HEIGHT)
    };
    return {
        (float)(x * transform.m00 + y * transform.m01) + 640,  
        (float)(x * transform.m10 + y * transform.m11) + 100   
    };
}
void Map::draw_map(){
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Vector2 screenPos = world_to_screen(x, y);
            int tileHeight = 1;
            draw_tile(screenPos, tileHeight, BLACK);
        }
    }
}

        