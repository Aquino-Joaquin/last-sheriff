#include "Zombie.h"
using namespace std;

Zombie::Zombie(int life, const char* skin_path, Vector2 position, float speed) 
: Robot(life,skin_path,position){
    this->speed_cooldown = speed;
}

bool Zombie::checkZombiePlayerCollision(Player& character,Map& world_map){
    return CheckCollisionRecs(getRectangle(world_map),character.getRectangle(world_map));
}
//basic follow method
void Zombie::follow_player(Player& my_player,Map& world_map){
    
    int newX = position.x;
    int newY = position.y;

    float currentTime = GetTime();

    if(currentTime - last_move > speed_cooldown){
        if(my_player.get_position().x > get_position().x){
            newX++;
            last_move = currentTime;
        }
        else if(my_player.get_position().x < get_position().x){
            newX--;
            last_move = currentTime;
        }
        else if(my_player.get_position().y > get_position().y){
            newY++;
            last_move = currentTime;
        }
        else if(my_player.get_position().y < get_position().y){
            newY--;
            last_move = currentTime;    
        }
        if(world_map.is_within_bounds(newX,newY)){
            position.x = newX;
            position.y = newY;
        }
    }
    
   

    draw_on_map(position,world_map);
    
}

void Zombie::attack(Player& my_player,Map& world_map,int force){
    
    follow_player(my_player,world_map);
    //cout<<checkZombiePlayerCollision(my_player,world_map)<<endl;
    if(check_collision(my_player,world_map)){
        my_player.set_life(my_player.get_life() - force); 
    }
    cout<<"Life: "<< my_player.get_life()<<endl;
    
    
};