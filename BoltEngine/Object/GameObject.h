#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include "IObject.h"
#include "Transform.h"
#include <string>
#include "SDL.h"
#include "Point.h"

struct Properties
{
    Properties(std::string textureid, int width, int height, int x, int y, SDL_RendererFlip flip = SDL_FLIP_NONE)
    {
        X = x;
        Y = y;
        Width = width;
        Height = height;
        Textureid = textureid;
        Flip = flip;

    }
public:
    int Width, Height;
    std::string Textureid;
    SDL_RendererFlip Flip;
    float X, Y;
};


class GameObject: public IObject
{

    protected:
    std::string m_textureID;
    Transform *trans;
    int m_width, m_height;

    SDL_RendererFlip m_flip;

    Point *origin;


public:
    GameObject(Properties* props): m_textureID(props->Textureid),
    m_width(props->Width), m_height(props->Height), m_flip(props->Flip) {
        trans = new Transform(props->X, props->Y);

        float px = props->X + props->Width/2;
        float py = props->Y + props->Height/2;

        origin = new Point(px, py);
    }

    inline Point* Get_origin()
    {
        return origin;
    }

    virtual void Draw() = 0;
    virtual void Update(float dt) = 0;
    virtual void Clean() = 0;



};


#endif // GAMEOBJECT_H
