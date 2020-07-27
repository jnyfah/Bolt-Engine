#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include "Layer.h"


class GameMap
{
    public:
        GameMap()

        {

        }
        void Render()
        {
            for(unsigned int i=0; i< map_layer.size(); i++)
            {
                map_layer[i]->Render();
            }
        }
        void Update()
        {
            for(unsigned int i=0; i< map_layer.size(); i++)
            {
                map_layer[i]->Update();
            }
        }

    std::vector <Layer*> Get_maplayer()
    {
        return map_layer;
    }
    private:
        friend class MapParser;
        std::vector<Layer*> map_layer;
};

#endif // GAMEMAP_H
