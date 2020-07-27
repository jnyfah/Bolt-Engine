#include "MapParser.h"
#include <iostream>
#include <string>


MapParser* MapParser::Instance = nullptr;

bool MapParser::load()
{

    return parse("Level1", "assets/maps/map.tmx");
}

void MapParser::clean()
{
   std::map<std::string, GameMap*>::iterator it;
   for(it = m_map.begin(); it != m_map.end(); it++)
   {
       it->second = nullptr;
   }
   m_map.clear();
}



bool MapParser::parse(std::string id, std::string source)
{
   TiXmlDocument xml;
   xml.LoadFile(source);

   if(xml.Error())
   {
       std::cerr<< "failed to load"<< source<< std::endl;
       return false;
   }

  TiXmlElement* root =xml.RootElement();
  int rowcount, colcount, tilesize = 0;

  root->Attribute("width", &colcount);
  root->Attribute("height", &rowcount);
  root->Attribute("tilewidth", &tilesize);

  Tilesetlist tilesets;

  for(TiXmlElement* e = root->FirstChildElement(); e!=nullptr; e = e->NextSiblingElement())
  {
      if(e->Value() == std::string("tileset"))
      {

          tilesets.push_back(ParseTileSet(e));
      }
  }

  GameMap* gamemap = new GameMap();
  for(TiXmlElement* e = root->FirstChildElement(); e!=nullptr; e = e->NextSiblingElement())
  {
      if(e->Value() == std::string("layer"))
      {
          TileLayer* tilelayer = ParseTileLayer(e, tilesets, tilesize, rowcount, colcount);
          gamemap->map_layer.push_back(tilelayer);
      }
  }

  m_map[id] = gamemap;
  return true;

}



Tileset MapParser::ParseTileSet(TiXmlElement* xmlTileset)
{
  Tileset tileset;
  tileset.name = xmlTileset->Attribute("name");
  xmlTileset->Attribute("firstgid", &tileset.first_id);

  xmlTileset->Attribute("tilecount", &tileset.tile_count);
  tileset.last_id = (tileset.first_id + tileset.tile_count) -1;

  xmlTileset->Attribute("columns", &tileset.num_cols);
  tileset.num_rows = tileset.tile_count/tileset.num_cols;
  xmlTileset->Attribute("tilewidth", &tileset.tile_size);

  TiXmlElement *image = xmlTileset->FirstChildElement();
  tileset.source = image->Attribute("source");

  return tileset;
}

TileLayer* MapParser::ParseTileLayer(TiXmlElement* xmlLayer, Tilesetlist tilesets, int tilesize, int rowcount, int colcount)
{
   TiXmlElement *data;



   for(TiXmlElement* e = xmlLayer->FirstChildElement();   e!= nullptr; e = e->NextSiblingElement())
   {
       if(e->Value() == std::string("data"))
       {
           data = e;
           break;
       }
   }

std::string matrix (data->GetText());
   std::stringstream iss(matrix);
   std::string id;

   Tilemap tilemap(rowcount, std::vector<int>(colcount, 0));

    for(int row = 0; row < rowcount; row++)
    {
        for(int col = 0; col < colcount;  col++)
        {
            getline(iss, id, ',');
            std::stringstream converter(id);
            converter >> tilemap[row][col];

            if(!iss.good())
            {
               break;
            }
        }
    }



    return (new TileLayer (tilesize, rowcount, colcount, tilemap, tilesets));
}
