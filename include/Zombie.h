#pragma once
#include "Robot.h"
class Zombie : public Robot{
    public:
        Zombie(int life, const char* skin_path) : Robot(life,skin_path){}
        void attack();

};