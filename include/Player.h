#pragma once
#include "Robot.h"
#include "Map.h"

class Player : public Robot{
    private:
        int playerX = 5;
        int playerY = 5;
    public:
        Player(int life, const char* skin_path,int pos_x,int pos_y);
        void move_player(Map& world_map);

};