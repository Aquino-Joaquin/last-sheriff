#include "Gun.h"
#include <math.h>
#include "Player.h"
Gun::Gun(){

}
Gun::Gun(Vector2 gun_position, const char* gun_texture_path, int gun_damage, float gun_speed)
      
{
    this->gun_position = gun_position;
    gun_texture = LoadTexture(gun_texture_path);
    this->gun_damage = gun_damage;
    this->gun_speed = gun_speed;
    this->last_fire_time = 0.0;
}

void Gun::fire_gun(Player& player) {
    if (GetTime() - last_fire_time >= gun_speed) {
        bullets.push_back(Bullet(gun_position, player.last_direction, gun_speed));
        last_fire_time = GetTime();
    }
}



void Gun::draw(){
    
    Vector2 position_on_map = Map::world_to_screen(gun_position.x,gun_position.y);
    DrawTexture(gun_texture,position_on_map.x,position_on_map.y,WHITE);

}
void Gun::update(Vector2 player_position){
    gun_position.x = player_position.x + 0.5;
    gun_position.y = player_position.y;
 }

