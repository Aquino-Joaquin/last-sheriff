#include "raylib.h"
#include "Map.h"
#include "resource_dir.h"  // Utility header for setting the resource directory
#include <iostream>
using namespace std;
#include "Menu.h"
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Gun.h"
#include "Game.h"

int main() {

    Game my_game;
    my_game.init();
    my_game.run();

    return 0;
}
