#include "Tile.h"
#include "Map.h"
#include <iostream>
using namespace std;

Tile::Tile(Vector2 position, float depth, Color sideColor,bool walkable) {

    this->position = position;
    this->depth = depth;  
    this->sideColor = sideColor;
    this->walkable = walkable;

    Vector2 screenPos = Map::world_to_screen(position.x, position.y);
    
    float h = depth * tile_height;

    // Define the four corners of the top face of the tile
    Vector2 top    = { screenPos.x, screenPos.y - h };
    Vector2 right  = { screenPos.x + tile_width / 2, screenPos.y + tile_height / 2 - h };
    Vector2 bottom = { screenPos.x, screenPos.y + tile_height - h };
    Vector2 left   = { screenPos.x - tile_width / 2, screenPos.y + tile_height / 2 - h };

    collisionEdges.push_back({top, right});
    collisionEdges.push_back({right, bottom});
    collisionEdges.push_back({bottom, left});
    collisionEdges.push_back({left, top});


}

void Tile::draw() {
    Vector2 screenPos = Map::world_to_screen(position.x, position.y);
    
    float h = depth * tile_height;

    // Define the four corners of the top face of the tile
    Vector2 top    = { screenPos.x, screenPos.y - h };
    Vector2 right  = { screenPos.x + tile_width / 2, screenPos.y + tile_height / 2 - h };
    Vector2 bottom = { screenPos.x, screenPos.y + tile_height - h };
    Vector2 left   = { screenPos.x - tile_width / 2, screenPos.y + tile_height / 2 - h };

    // Draw top face of the tile (two triangles)
    DrawTriangle(top, bottom, right, sideColor);
    DrawTriangle(bottom, top, left, sideColor);

    // Define and draw the right face
    Vector2 r1 = right;
    Vector2 r2 = { right.x, right.y + h };
    Vector2 b1 = bottom;
    Vector2 b2 = { bottom.x, bottom.y + h };
    DrawTriangle(r1, b1, r2, sideColor);
    DrawTriangle(r2, b1, b2, sideColor);

    // Define and draw the left face
    Vector2 l1 = left;
    Vector2 l2 = { left.x, left.y + h };
    DrawTriangle(l1, l2, b1, sideColor);
    DrawTriangle(l2, b2, b1, sideColor);

    // Draw edges to outline the top face
    DrawLineV(top, right, DARKGRAY);
    DrawLineV(right, bottom, DARKGRAY);
    DrawLineV(bottom, left, DARKGRAY);
    DrawLineV(left, top, DARKGRAY);


}
void Tile::drawCollisionEdges() {
    for (const auto& edge : collisionEdges) {
        DrawLineV(edge.first, edge.second, RED); // You can choose any color
    }
}

bool Tile::checkRectangleLineCollision(Rectangle rect, const std::vector<std::pair<Vector2, Vector2>>& lines) {
    // Convert the rectangle into 4 lines (edges)
    Vector2 r1 = { rect.x, rect.y };
    Vector2 r2 = { rect.x + rect.width, rect.y };
    Vector2 r3 = { rect.x + rect.width, rect.y + rect.height };
    Vector2 r4 = { rect.x, rect.y + rect.height };

    // Draw the rectangle edges for debugging purposes
    DrawLineV(r1, r2, DARKGRAY);
    DrawLineV(r2, r3, DARKGRAY);
    DrawLineV(r3, r4, DARKGRAY);
    DrawLineV(r4, r1, DARKGRAY);

    // Store the rectangle's edges as pairs of points
    Vector2 rectEdges[4][2] = {
        {r1, r2}, {r2, r3}, {r3, r4}, {r4, r1}
    };

    // Check collision between each rectangle edge and each tile edge
    for (int i = 0; i < 4; i++) {
        for (const auto& line : lines) {
            if (CheckCollisionLines(rectEdges[i][0], rectEdges[i][1], line.first, line.second, nullptr)) {
                return true; // Collision detected
            }
        }
    }

    return false; // No collision
}

