#pragma once
#include "raylib.h"
class Animation{
    private:
        Texture2D image;
        
        float running_time;
        float update_time;
        int columns;
        int rows;
        float scale;
        int start_frame;
        int end_frame;
        int frame = start_frame;
        int attack_action_frame;
        int attack_frame = attack_action_frame;
        int attack_action_end_frame;
        
        bool attack_finished = false;
        
    public:
        Animation();
        Animation(Texture2D image,int columns,int rows,float update_time,float scale,int start_frame,int end_frame,int frame_start,int frame_end);
        void animate(Vector2 position,int direction,bool moving,bool shoting);
        Vector2 image_dimension();
        bool isAttackFinished() const;
};