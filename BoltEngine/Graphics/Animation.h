#ifndef ANIMATION_H
#define ANIMATION_H
#include"SDL.h"
#include <string>


class Animation
{
    public:
        Animation(){}

        void update();
        void draw(float x,float y,int sprite_width, int sprite_height);
        void setprops(std::string text_ID, int sprite_row, int anim_speed, int frame_count, SDL_RendererFlip flip = SDL_FLIP_NONE);





    private:
        int sprite_row, sprite_frame;
        int anim_speed, frame_count;
        std::string text_ID;
        SDL_RendererFlip flip;

};

#endif // ANIMATION_H
