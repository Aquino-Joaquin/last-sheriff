#pragma once
#include "Robot.h"
#include "Map.h"

class Player : public Robot{
    
    public:
        Player();
        Player(int life,Vector2 position,Animation skin_animated,Rectangle hitBox);
        void move_player(Map& world_map);
        int last_direction = 1;
        

};