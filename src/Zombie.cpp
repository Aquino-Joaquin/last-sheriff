#include "Zombie.h"
using namespace std;

Zombie::Zombie(int life, const char* skin_path, Vector2 position, float speed) 
: Robot(life,skin_path,position){
    this->speed_cooldown = speed;
}

//basic follow method
void Zombie::follow_player(Player& my_player, Map& world_map) {
    float newX = position.x;
    float newY = position.y;

    float currentTime = GetTime();

    if (currentTime - last_move > speed_cooldown) {

        if (my_player.get_position().x > get_position().x) {
            newX += 0.1;
        } else if (my_player.get_position().x < get_position().x) {
            newX -= 0.1;
        }

        if (my_player.get_position().y > get_position().y) {
            newY += 0.1;
        } else if (my_player.get_position().y < get_position().y) {
            newY -= 0.1;
        }

        Rectangle newRect = getRectangleAt(newX, newY);
        if (world_map.is_walkable(newRect)) {
            position.x = newX;
            position.y = newY;
            last_move = currentTime; 
        }
    }

    draw_on_map(position, world_map);
}

void Zombie::attack(Player& my_player,Map& world_map,int force){
    if(my_player.alive){
        follow_player(my_player,world_map);
        if(check_collision(my_player,world_map)){
            my_player.set_life(my_player.get_life() - force); 
        }
    }  
    
};
