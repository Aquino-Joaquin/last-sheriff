#include "Bullet.h"
#include <iostream>
using namespace std;

Bullet::Bullet(Vector2 start, int direction,float speed) {
    position = start;
    active = true;
    this->direction = direction;
}

void Bullet::update() {
    
    if(direction == 1){
        position.x += 0.3;
    }else if(direction == 2){
        position.x -= 0.3;
    }else if(direction == 3){
        position.y += 0.3;
    }else if(direction == 4){   
        position.y -= 0.3;
    }
    
}

void Bullet::draw(Map& world_map) {
    if(active){
        Vector2 position_on_map = world_map.world_to_screen(position.x,position.y);
        DrawCircleV(position_on_map, radius, color);
    }
    if(!is_on_map(world_map)){
        active = false;
        cout<<"Funciona"<<endl;
    }
    
}

bool Bullet::is_on_map(Map& world_map) const {
    return world_map.is_within_bounds(position.x,position.y);
}
