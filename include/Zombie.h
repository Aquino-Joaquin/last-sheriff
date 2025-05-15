#pragma once
#include "Robot.h"
#include "Player.h"
#include "Gun.h"
#include <vector>
class Zombie : public Robot{
    private:
        float speed_cooldown;
        float last_move;
        float last_attack_time = 0.0f;
        float attack_cooldown = 1.0f;
    public:
        Zombie(int life,Vector2 position, float speed,Animation skin_animated,Rectangle hitBox);
        void attack(Player& my_player,Map& world_map ,int force,std::vector<Zombie>& all_zombies);
        void follow_player(Player& my_player,Map& world_map,std::vector<Zombie>& all_zombies);
        void take_damage(Gun& my_gun);
        bool collides_with_other_zombie(Rectangle& newRect, std::vector<Zombie>& all_zombies);

        

};