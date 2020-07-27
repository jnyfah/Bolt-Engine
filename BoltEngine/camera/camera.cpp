#include "camera.h"

camera *camera::instance = nullptr;

void camera::Update(float dt)
{
    if(Target != nullptr)
    {
        viewbox.x = Target->X - screen_width/2;
        viewbox.y = Target->Y - screen_height/2;

        if(viewbox.x < 0)
        {
           viewbox.x = 0;
        }

        if(viewbox.y < 0)
        {
           viewbox.y = 0;
        }

        if(viewbox.x > (2 * screen_width - viewbox.w))
        {
          viewbox.x = (2 * screen_width - viewbox.w);
        }

         if(viewbox.y > (2 * screen_height - viewbox.h))
        {
          viewbox.y = (2 * screen_height - viewbox.h);
        }

        postion = Vector2D(viewbox.x, viewbox.y);
    }


}




