#pragma once
#include "raylib.h"
#include "Map.h"

class Robot {
protected:
    int life;
    int max_life; // Life maximum for health bar
    Texture2D skin;
    Vector2 position;

public:
    bool alive = true;

    Robot();
    Robot(int life_robot, const char* skin_path, Vector2 position);
    
    int get_life();
    void set_life(int new_life);

    void draw_on_map();
    Rectangle getRectangle();
    Rectangle getRectangleAt(float x, float y);

    Vector2 get_position();
    bool check_collision(Robot& my_robot);
    bool is_alive();
};