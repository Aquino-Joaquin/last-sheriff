#include "Animation.h"

Animation::Animation(){}
Animation::Animation(Texture2D image, int columns,int rows,float update_time,float scale,int start_frame,int end_frame,int frame_start,int frame_end)
: image(image),columns(columns),rows(rows),update_time(update_time),scale(scale),start_frame(start_frame),end_frame(end_frame),
attack_action_frame(frame_start),attack_action_end_frame(frame_end){
    
}
void Animation::animate(Vector2 position,int direction,bool moving,bool shoting){
    float dt = GetFrameTime();
        running_time += dt;
        attack_finished = false;

    if (running_time > update_time) {
        running_time = 0;
        frame++;

        if (frame > end_frame) {
            frame = start_frame;
        }

        if (shoting) {
            attack_frame++;
            if (attack_frame > attack_action_end_frame) {
                attack_frame = attack_action_frame;
                attack_finished = true;
            }
        }
    }

        Rectangle source;
        if (shoting) {
            source = { (float)attack_frame * image.width / columns, (float)direction * image.height / rows,
                       (float)image.width / columns, (float)image.height / rows };
        } else if (moving) {
            source = { (float)frame * image.width / columns, (float)direction * image.height / rows,
                       (float)image.width / columns, (float)image.height / rows };
        } else {
            source = { 0, (float)direction * image.height / rows,
                       (float)image.width / columns, (float)image.height / rows };
        }

        Rectangle dest = { position.x, position.y, source.width * scale, source.height * scale };
        DrawTexturePro(image, source, dest, { 0, 0 }, 0.f, WHITE);
    
}
Vector2 Animation::image_dimension(){
    return {(image.width/columns)*scale,(image.height/rows)*scale};
}
bool Animation::isAttackFinished()const {
    return attack_finished;
}