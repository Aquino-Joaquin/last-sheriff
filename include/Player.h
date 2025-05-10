#pragma once
#include "Robot.h"
#include "Map.h"
#include "Gun.h"

class Player : public Robot{
    
    public:
        Player();
        Player(int life, const char* skin_path,Vector2 position);
        void move_player(Map& world_map);
        bool is_alive();

};