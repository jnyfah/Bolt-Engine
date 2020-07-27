#ifndef COLIDER_H
#define COLIDER_H

#include "SDL.h"


class colider
{
    public:
        colider() {}
        inline SDL_Rect Get()
        {
            return box;
        }

        inline void set_buffer(int x, int y, int w, int h)
        {
            buffer ={x, y, w, h};
        }
        void set(int x, int y, int w, int h)
        {
            box = {
               x - buffer.x,
               y - buffer.y,
               w - buffer.w,
               h - buffer.h,
            };
        }

    private:
        SDL_Rect box;
        SDL_Rect buffer;
};

#endif // COLIDER_H
