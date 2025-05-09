#pragma once
#include "raylib.h"
#include "Map.h"

class Bullet {
private:
    Vector2 position;
    int direction;
    bool active;
    float speed;
    float radius = 4.0f;
    Color color = RED;
    

public:
    Bullet(Vector2 start, int direction,float speed);
    void update();
    void draw();
    bool is_on_map() const;
};
