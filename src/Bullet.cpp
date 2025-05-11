#include "Bullet.h"
#include "Map.h"

Bullet::Bullet(Vector2 start, int direction, float speed) {
    position = start;
    active = true;
    this->direction = direction;
    this->speed = speed;
}

void Bullet::update() {
    if (!active) return;

    switch (direction) {
        case 1: position.x += speed; break;
        case 2: position.x -= speed; break;
        case 3: position.y += speed; break;
        case 4: position.y -= speed; break;
    }
}

void Bullet::draw() {
    if (!active) return;

    Vector2 position_on_map = Map::world_to_screen(position.x, position.y);
    DrawCircleV(position_on_map, radius, color);

    if (!is_on_map()) {
        active = false;
    }
}

bool Bullet::is_on_map() const {
    Vector2 screen_pos = Map::world_to_screen(position.x, position.y);
    return (screen_pos.x > 0 && screen_pos.x < GetScreenWidth()) &&
           (screen_pos.y > 0 && screen_pos.y < GetScreenHeight());
}

Vector2 Bullet::get_position() {
    return Map::world_to_screen(position.x, position.y);
}

float Bullet::get_radius() {
    return radius;
}

bool Bullet::is_active() const {
    return active;
}

void Bullet::set_active(bool state) {
    active = state;
}

bool Bullet::is_taken_damage() const {
    return taken_damage;
}

void Bullet::set_taken_damage(bool state) {
    taken_damage = state;
}
