#ifndef TILELAYER_H
#define TILELAYER_H

#include <string>
#include <vector>
#include <Layer.h>
#include "Vector2D.h"

struct Tileset
{
    int first_id, last_id;
    int num_rows, num_cols;
    int tile_count, tile_size;
    std::string name, source;

};


using Tilesetlist = std::vector<Tileset>;
using Tilemap = std::vector<std::vector<int> >;


class TileLayer : public Layer
{
public:
    TileLayer(int tilesize, int rowcount, int colcount, Tilemap tilemap, Tilesetlist tileset);

    virtual void Render();
    virtual void Update();
    inline Tilemap Get_tilemap()
    {
        return m_tilemap;
    }


private:
    int m_tile_size;
    int m_num_rows, m_num_cols;
    Tilemap m_tilemap;
    Tilesetlist m_tileset;
};

#endif // TILELAYER_H
