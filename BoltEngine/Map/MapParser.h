#ifndef MAPPARSER_H
#define MAPPARSER_H
#include <map>
#include <string>

#include "TileLayer.h"
#include "GameMap.h"
#include "tinyxml.h"


class MapParser
{
public:
    inline  static MapParser *Get_Instance()
    {
        if(Instance == nullptr)
        {
            Instance = new MapParser;
        }

        return Instance;
    }

    bool load();     //load the map
    void clean();

    inline GameMap *Getmap(std::string id)
    {
        return m_map[id];
    }

private:
    MapParser() {}
    static MapParser *Instance;
    std::map<std::string, GameMap*>m_map;
    bool parse(std::string, std::string);
    Tileset ParseTileSet(TiXmlElement*);
    TileLayer* ParseTileLayer(TiXmlElement*, Tilesetlist, int, int, int);

};

#endif // MAPPARSER_H
