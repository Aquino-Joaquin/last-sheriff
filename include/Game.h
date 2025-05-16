#pragma once
#include "raylib.h"
#include "resource_dir.h" 
#include "Map.h"
#include "Menu.h"
#include "Player.h"
#include "Zombie.h"
#include <vector>
#include "Gun.h"

class Game {
public:
    Game();
    ~Game();
    void run();
    void init();
    void update();
    void draw();

    int round;                // Current round number
    int zombies_killed;       // Number of zombies killed in current round
    int alive_zombies = 0;

    Sound enviroment_sound;

    Texture2D zombie_texture;

    void spawn_zombies(); // Starts the zombie spawning process

private:
    Map map;
    Player my_player;
    Gun my_gun;
    std::vector<Zombie> enemies;
    Menu start_menu;
    Menu end_menu;

    // Progressive zombie spawn variables
    int zombies_to_spawn = 0;                  
    float zombie_spawn_timer = 0.0f;            
    float zombie_spawn_delay = 2.5f;            
    Vector2 zombie_spawn_position = {17, -19};    
    int base_zombie_life = 100;                 
    float zombie_speed = 0.1f;                  
    bool spawning = false;                      

    void update_zombie_spawning(float deltaTime); 
};
