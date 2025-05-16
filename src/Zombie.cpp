#include "Zombie.h"
#include <iostream>
#include <math.h>
using namespace std;

Zombie::Zombie(int life,  Vector2 position,float speed, Animation skin_animated,Rectangle hitBox) 
: Robot(life,position,skin_animated,hitBox){
    this->speed_cooldown = speed;
    this->last_move = GetTime();
}

//basic follow method
void Zombie::follow_player(Player& my_player, Map& world_map, std::vector<Zombie>& all_zombies) {
    if (!alive) return;

    float currentTime = GetTime();
    if ((currentTime - last_move) < speed_cooldown) return;

    float step = 0.1f;
    Vector2 target = my_player.get_position();

    float diffX = target.x - position.x;
    float diffY = target.y - position.y;

    bool moved = false;

    if (fabs(diffX) > fabs(diffY)) {
        if (diffX > 0.1f) {
            float newX = position.x + step;
            Rectangle rectX = getRectangleAt(newX, position.y);
            if (world_map.is_walkable(rectX) && !collides_with_other_zombie(rectX, all_zombies)) {
                position.x = newX;
                animation_direction = 5; // right
                moving = true;
                moved = true;
            }
        } else if (diffX < -0.1f) {
            float newX = position.x - step;
            Rectangle rectX = getRectangleAt(newX, position.y);
            if (world_map.is_walkable(rectX) && !collides_with_other_zombie(rectX, all_zombies)) {
                position.x = newX;
                animation_direction = 1; // left
                moving = true;
                moved = true;

            }
        }
    }

    if (!moved) {
        if (diffY > 0.1f) {
            float newY = position.y + step;
            Rectangle rectY = getRectangleAt(position.x, newY);
            if (world_map.is_walkable(rectY) && !collides_with_other_zombie(rectY, all_zombies)) {
                position.y = newY;
                animation_direction = 7; // up
                moving = true;
                moved = true;

            }
        } else if (diffY < -0.1f) {
            float newY = position.y - step;
            Rectangle rectY = getRectangleAt(position.x, newY);
            if (world_map.is_walkable(rectY) && !collides_with_other_zombie(rectY, all_zombies)) {
                position.y = newY;
                animation_direction = 3; // down
                moving = true;
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
