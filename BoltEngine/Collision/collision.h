#ifndef COLLISION_H
#define COLLISION_H
#include "SDL.h"
#include <vector>
#include "../Engine.h"
#include "TileLayer.h"
#include "GameMap.h"


class collision
{
    public:
        bool checkcollision(SDL_Rect a, SDL_Rect b);
        bool mapcollision(SDL_Rect a);

        inline static collision* Get_instance()
        {
            if(instance != nullptr)
            {
                return instance;
            }
            else
            {
                return instance = new collision();
            }
        }

    private:
        collision();
        Tilemap collision_tilemap;
        TileLayer *collision_layer;
        static collision* instance;
};

#endif // COLLISION_H
