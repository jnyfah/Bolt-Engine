#include "TileLayer.h"
#include "Texture.h"


TileLayer::TileLayer(int tilesize, int rowcount, int colcount, Tilemap tilemap, Tilesetlist tileset):
     m_tile_size(tilesize), m_num_rows(rowcount), m_num_cols(colcount), m_tilemap (tilemap), m_tileset(tileset)
{

    for(unsigned int i =0; i < m_tileset.size(); i++)
    {
        Texture::Getinstance()->Load(m_tileset[i].name, "assets/maps/" + m_tileset[i].source);
    }
}

void TileLayer::Render()
{
    for (unsigned int i = 0; i< static_cast<unsigned int>(m_num_rows); i++)
    {
        for(unsigned int j = 0; j < static_cast<unsigned int>(m_num_cols); j++)
        {
            int tileID = m_tilemap[i][j];

            if(tileID == 0)
            {
                continue;
            }
            else
            {
                int index;
                if(m_tileset.size() > 1)
                {
                    for (unsigned int k = 1; k <m_tileset.size(); k++)
                    {
                        if(tileID > m_tileset[k].first_id && tileID < m_tileset[k].last_id)
                        {
                            tileID = tileID + m_tileset[k].tile_count - m_tileset[k].last_id;
                            index = k;
                            break;
                        }
                    }
                }


                Tileset ts = m_tileset[index];
                int tilerow  = tileID/ts.num_cols;
                int tilecols = tileID - tilerow * ts.num_cols - 1;

                if(tileID % ts.num_cols == 0)
                {
                    tilerow--;
                    tilecols = ts.num_cols - 1;
                }
                Texture::Getinstance()->DrawTile(ts.name, ts.tile_size, j*ts.tile_size, i*ts.tile_size, tilerow, tilecols);
            }
        }
    }
}

void TileLayer::Update()
{

}
