#include "collision.h"
#include "../Engine.h"

collision *collision::instance = nullptr;
bool collision::checkcollision(SDL_Rect a, SDL_Rect b)
{
    bool x_overlap = (a.x < b.x + b.w) && (a.x + a.w > b.x);
    bool y_overlap = (a.y < b.y + b.h) && (a.y + a.h > b.y);

    return (x_overlap && y_overlap);
}

bool collision::mapcollision(SDL_Rect a)
{
    int tilesz = 32;
    int rwcount = 20;
    int colcount = 60;

    int left_tile = a.x/tilesz;
    int right_tile = (a.x + a.w)/tilesz;

    int top_tile = a.y/tilesz;
    int bottom_tile = (a.y + a.h)/tilesz;

    if(left_tile < 0)
        left_tile = 0;
    if(right_tile > colcount)
        right_tile = colcount;

    if(top_tile < 0)
        top_tile = 0;
    if(bottom_tile > rwcount)
        bottom_tile = rwcount;

    for(int i = left_tile; i<= right_tile; ++i)
    {
        for(int j = top_tile; j <= bottom_tile; ++j)
        {
            if(collision_tilemap[j][i] > 0)
                return true;
        }
    }


    return false;
}

collision::collision()
{
  collision_layer = (TileLayer*)Engine::Get_instance()->GetMap()->Get_maplayer().front();
  collision_tilemap = collision_layer->Get_tilemap();
}

