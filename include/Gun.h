#pragma once
#include "raylib.h"
#include "Bullet.h"
#include <vector>
#include "Map.h"
#include "Player.h"
class Gun {
private:
    Vector2 gun_position;     
    Texture2D gun_texture;

      
    float gun_speed;
    float last_fire_time;

public:
    Sound gun_sound;
    int last_direction = 1; 
    int gun_damage;  
    std::vector<Bullet> bullets;
    Gun();
    Gun(Vector2 gun_position, const char* gun_texture,const char* gun_sound_path, int gun_damage, float gun_speed);
    void fire_gun(Player& player);         
    void draw();
    void update(Vector2 player_position);
};