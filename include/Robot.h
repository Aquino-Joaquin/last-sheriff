#pragma once
#include "raylib.h"
#include "Map.h"
#include "Animation.h"

class Robot {
protected:
    int life;
    int max_life; // Life maximum for health bar
    Vector2 position;
    Animation skin_animated;
    Rectangle hitboxOffset; 

public:
    bool alive = true;
    int animation_direction;
    bool moving;
    bool attack_action = false;

    Robot();
    Robot(int life_robot, Vector2 position,Animation skin_animated,Rectangle hitBox);
    
    int get_life();
    void set_life(int new_life);

    void draw_on_map();
    Rectangle getRectangle();
    Rectangle getRectangleAt(float x, float y);

    Vector2 get_position();
    bool check_collision(Robot& my_robot);
    bool is_alive();
    Rectangle getCollisionBox();
};