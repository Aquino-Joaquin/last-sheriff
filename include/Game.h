#pragma once
#include "raylib.h"
#include "resource_dir.h" 
#include "Map.h"
#include "Menu.h"
#include "Player.h"
#include "Zombie.h"
#include <vector>
#include "Gun.h"

class Game{
    public:
        Game();
        ~Game();
        void run();
        void init();
        void update();
        void draw();


    private:
        Map map;
        Player my_player;
        Gun my_gun;
        std::vector<Zombie> enemies;
        Menu start_menu;
        Menu end_menu;
};