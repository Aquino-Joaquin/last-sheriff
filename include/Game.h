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

    void spawn_zombies(); // Starts the zombie spawning process

private:
    Map map;
    Player my_player;
    Gun my_gun;
    std::vector<Zombie> enemies;
    Menu start_menu;
    Menu end_menu;

    // Progressive zombie spawn variables
    int zombies_to_spawn = 0;                   // How many zombies are left to spawn
    float zombie_spawn_timer = 0.0f;            // Timer to control spawn delay
    float zombie_spawn_delay = 2.5f;            // Delay between each zombie spawn
    Vector2 zombie_spawn_position = {20, 5};    // Fixed spawn location
    int base_zombie_life = 100;                 // Life of zombies in current round
    float zombie_speed = 0.1f;                  // Speed of spawned zombies
    bool spawning = false;                      // Whether zombies are currently spawning

    void update_zombie_spawning(float deltaTime); // Called every frame to spawn zombies progressively
};
