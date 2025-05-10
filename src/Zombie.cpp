#include "Zombie.h"
using namespace std;

Zombie::Zombie(int life, const char* skin_path, Vector2 position, float speed) 
: Robot(life,skin_path,position){
    this->speed_cooldown = speed;
    this->last_move = GetTime();
}

//basic follow method
void Zombie::follow_player(Player& my_player, Map& world_map, std::vector<Zombie>& all_zombies){
    if(alive){
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
            if (world_map.is_walkable(newRect) && !collides_with_other_zombie(newRect,all_zombies)) {
                position.x = newX;
                position.y = newY;
                last_move = currentTime; 
            }
        }
   
    }
    
}

void Zombie::attack(Player& my_player,Map& world_map,int force,std::vector<Zombie>& all_zombies){
    if(my_player.alive){
        follow_player(my_player,world_map,all_zombies);
        if(check_collision(my_player)){
            my_player.set_life(my_player.get_life() - force); 
        }
    }  
    
}
void Zombie::check_alive(Gun my_gun){

    for(auto& bullet:my_gun.bullets){
        if(CheckCollisionCircleRec(bullet.get_position(),bullet.get_radius(),getRectangle())){
            set_life(get_life() - my_gun.gun_damage);
            if(get_life() <= 0 ){
                alive = false;
            }
            cout<<"Life: "<<get_life()<<endl;
        }
        
    }

    
}
bool Zombie::collides_with_other_zombie(Rectangle& newRect, std::vector<Zombie>& all_zombies){
    for (auto& zombie : all_zombies) {
        if (&zombie == this || !zombie.alive) continue; // Ignora a sí mismo o zombies muertos
        if (CheckCollisionRecs(newRect,zombie.getRectangle())) {
            return true;
        }
    }
    return false;
}
