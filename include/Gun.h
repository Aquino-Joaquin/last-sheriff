#pragma once
#include "raylib.h"
#include <string>
#include "Bullet.h"
#include <vector>
#include "Map.h"
#include "Player.h"
class Gun {
private:
    std::string name;         
    Vector2 gun_position;     
    Texture2D gun_texture;

    int gun_damage;    
    float gun_speed;
    float last_fire_time;

   
    int ammo_count;           

public:
    std::vector<Bullet> bullets;
    Gun(std::string name, Vector2 gun_position, const char* gun_texture, int gun_damage, int ammo_count,float gun_speed);
    void fire_gun();         
    void draw();
    void update(Player my_player);
    int get_ammo_count() const;  
};