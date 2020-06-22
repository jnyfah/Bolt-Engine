#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include "IObject.h"
#include "Transform.h"'
#include <string>
#include "SDL.h"

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
public:
    GameObject(Properties* props): m_textureID(props->Textureid),
    m_width(props->Width), m_height(props->Height), m_flip(props->Flip) {
        trans = new Transform(props->X, props->Y);
    }

    virtual void Draw() = 0;
    virtual void Update(float dt) = 0;
    virtual void Clean() = 0;


protected:

    Transform *trans;
    int m_width, m_height;
    std::string m_textureID;
    SDL_RendererFlip m_flip;
};


#endif // GAMEOBJECT_H
