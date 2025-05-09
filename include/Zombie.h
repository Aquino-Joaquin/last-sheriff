#pragma once
#include "Robot.h"
#include "Player.h"

class Zombie : public Robot{
    private:
        float speed_cooldown;
        float last_move;
    public:
        Zombie(int life, const char* skin_path,Vector2 position, float speed);
        void attack(Player& my_player,Map& world_map ,int force);
        void follow_player(Player& my_player,Map& world_map);

        

};