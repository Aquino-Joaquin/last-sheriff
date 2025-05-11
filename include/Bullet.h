#pragma once
#include "raylib.h"

class Bullet {
private:
    Vector2 position;
    int direction;
    float speed = 0.3f;
    float radius = 5.0f;
    Color color = RED;
    bool active = true;
    bool taken_damage = false;

public:
    Bullet(Vector2 start, int direction, float speed);

    void update();
    void draw();
    bool is_on_map() const;

    Vector2 get_position();
    float get_radius();

    bool is_active() const;
    void set_active(bool state);

    bool is_taken_damage() const;
    void set_taken_damage(bool state);
};
