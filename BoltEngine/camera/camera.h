#ifndef CAMERA_H
#define CAMERA_H

#include "Point.h"
#include "Vector2D.h"
#include "SDL.h"

#include "../Engine.h"


class camera
{
public:
    inline static camera *Get_instance()
    {
        if(instance != nullptr)
        {
            return instance;
        }
        else
        {
            return instance = new camera();
        }
    }


    inline SDL_Rect Get_viewbox()
    {
        return viewbox;
    }


    inline Vector2D Get_postion()
    {
        return postion;
    }

    inline void set_target(Point* t)
    {
        Target = t;
    }

    void Update(float dt);

private:
    camera(){viewbox = {0, 0, screen_width, screen_height};}
    static camera* instance;

    Point *Target;
    Vector2D postion;
    SDL_Rect viewbox;
};

#endif // CAMERA_H
