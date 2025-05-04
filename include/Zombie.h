#pragma once
#include "Robot.h"
class Zombie : public Robot{
    public:
        Zombie(int life, const char* skin_path,int pos_x, int pos_y);
        void attack();

};