#include "TileLayer.h"


TileLayer::TileLayer(int tilesize, int width, int height, Tilemap tilemap, Tilesetlist tileset)
{
    m_tile_size = tilesize;
    m_num_rows = width;
    m_num_cols = height;
    m_tilemap = tilemap;
    m_tileset = tileset;
}

void TileLayer::Render()
{

}

void TileLayer::update(float dt)
{

}
