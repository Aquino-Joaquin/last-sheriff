#pragma once
#include "raylib.h"
#include "Map.h"
#include <iostream>
using namespace std;
class Robot{
    private:
        int life;
    protected:
        Texture2D skin;
        Vector2 position;
    public:
        int get_life();
        void set_life(int life);
        Robot(int life, const char* skin_path,Vector2 position);
        void draw_on_map(Vector2 position,Map& wordl_map);
        Rectangle getRectangle(Map& world_map);
        Vector2 get_position();
        bool check_collision(Robot& my_robot, Map& world_map);
        // ~Robot();

};