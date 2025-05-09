#include "Gun.h"
#include <math.h>
Gun::Gun(std::string name, Vector2 gun_position, const char* gun_texture_path, int gun_damage, int ammo_count,float gun_speed)
      
{
    this->name = name;
    this->gun_position = gun_position;
    gun_texture = LoadTexture(gun_texture_path);
    this->gun_damage = gun_damage;
    this->ammo_count = ammo_count;
    this->gun_speed = gun_speed;
    this->last_fire_time = 0.0;
}

void Gun::fire_gun(){
    
    if(GetTime() - last_fire_time >= gun_speed){
        Vector2 bullet_on_map = Map::world_to_screen(gun_position.x,gun_position.y);
        if (IsKeyDown(KEY_W)) { 
            bullets.push_back(Bullet(gun_position,4,gun_speed));
        }
        else if (IsKeyDown(KEY_S)) { 
            bullets.push_back(Bullet(gun_position,3,gun_speed));
        }
        else if (IsKeyDown(KEY_D)) { 
            bullets.push_back(Bullet(gun_position,1,gun_speed));
        }
        else if (IsKeyDown(KEY_A)) { 
            bullets.push_back(Bullet(gun_position,2,gun_speed));
        }
        last_fire_time = GetTime();
    }

}
int Gun::get_ammo_count() const{
    return ammo_count;
}
void Gun::draw(){
    
    Vector2 position_on_map = Map::world_to_screen(gun_position.x,gun_position.y);
    DrawTexture(gun_texture,position_on_map.x,position_on_map.y,WHITE);

}
void Gun::update(Player my_player){
    gun_position.x = my_player.get_position().x + 0.5;
    gun_position.y = my_player.get_position().y;
    draw();
 }

