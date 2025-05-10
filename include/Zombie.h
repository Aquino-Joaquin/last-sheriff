#pragma once
#include "Robot.h"
#include "Player.h"
#include "Gun.h"
#include <vector>
class Zombie : public Robot{
    private:
        float speed_cooldown;
        float last_move;
    public:
        Zombie(int life, const char* skin_path,Vector2 position, float speed);
        void attack(Player& my_player,Map& world_map ,int force,std::vector<Zombie>& all_zombies);
        void follow_player(Player& my_player,Map& world_map,std::vector<Zombie>& all_zombies);
        void check_alive(Gun my_gun);
        bool collides_with_other_zombie(Rectangle& newRect, std::vector<Zombie>& all_zombies);

        

};