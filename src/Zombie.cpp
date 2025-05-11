#include "Zombie.h"
#include <iostream>
using namespace std;

Zombie::Zombie(int life, const char* skin_path, Vector2 position, float speed) 
: Robot(life,skin_path,position){
    this->speed_cooldown = speed;
    this->last_move = GetTime();
}

//basic follow method
void Zombie::follow_player(Player& my_player, Map& world_map, std::vector<Zombie>& all_zombies) {
    if (!alive) return;

    float currentTime = GetTime();
    if (currentTime - last_move < speed_cooldown) return;

    float step = 0.1f;
    Vector2 target = my_player.get_position();
    bool moved = false;

    // Determine the differences in X and Y with respect to the player
    float diffX = target.x - position.x;
    float diffY = target.y - position.y;

    // 1. Try moving in both X and Y simultaneously (diagonally) if possible
    if (abs(diffX) > 0.1f && abs(diffY) > 0.1f) {
        // Diagonal movement: adjust X and Y simultaneously
        float newX = position.x + (diffX > 0 ? step : -step);
        float newY = position.y + (diffY > 0 ? step : -step);
        
        Rectangle newRect = getRectangleAt(newX, newY);
        if (world_map.is_walkable(newRect) && !collides_with_other_zombie(newRect, all_zombies)) {
            position.x = newX;
            position.y = newY;
            moved = true;
        }
    }
    
    // 2. If unable to move diagonally, try moving in X or Y separately
    if (!moved) {
        // First, try moving in X
        if (abs(diffX) > 0.1f) {
            float newX = position.x + (diffX > 0 ? step : -step);
            Rectangle rectX = getRectangleAt(newX, position.y);
            if (world_map.is_walkable(rectX) && !collides_with_other_zombie(rectX, all_zombies)) {
                position.x = newX;
                moved = true;
            }
        }

        // Then try moving in Y if not moved in X
        if (!moved && abs(diffY) > 0.1f) {
            float newY = position.y + (diffY > 0 ? step : -step);
            Rectangle rectY = getRectangleAt(position.x, newY);
            if (world_map.is_walkable(rectY) && !collides_with_other_zombie(rectY, all_zombies)) {
                position.y = newY;
                moved = true;
            }
        }
    }

    if (moved) {
        last_move = currentTime;
    }
}



void Zombie::attack(Player& my_player, Map& world_map, int force, std::vector<Zombie>& all_zombies) {
    if (!my_player.alive) return;

    follow_player(my_player, world_map, all_zombies);

    if (check_collision(my_player)) {
        float currentTime = GetTime();
        if (currentTime - last_attack_time >= attack_cooldown) {
            my_player.set_life(my_player.get_life() - force); 
            last_attack_time = currentTime;
        }
    }
}
void Zombie::take_damage(Gun& my_gun) {
    for (auto& bullet : my_gun.bullets) {
        if (bullet.is_taken_damage() || !bullet.is_active()) continue;

        if (CheckCollisionCircleRec(bullet.get_position(), bullet.get_radius(), getRectangle())) {
            set_life(get_life() - my_gun.gun_damage);
            bullet.set_taken_damage(true);
            bullet.set_active(false);

            if (get_life() <= 0) {
                alive = false;
            }

            std::cout << "Life: " << get_life() << std::endl;
        }
    }
}
bool Zombie::collides_with_other_zombie(Rectangle& newRect, std::vector<Zombie>& all_zombies){
    for (auto& zombie : all_zombies) {
        if (&zombie == this || !zombie.alive) continue; 
        if (CheckCollisionRecs(newRect,zombie.getRectangle())) {
            return true;
        }
    }
    return false;
}
