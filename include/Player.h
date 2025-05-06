#pragma once
#include "Robot.h"
#include "Map.h"

class Player : public Robot{
    
    public:
        Player(int life, const char* skin_path,Vector2 position);
        void move_player(Map& world_map);

};