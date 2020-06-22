#ifndef TEXTURE_H
#define TEXTURE_H
#include "SDL.h"
#include "SDL_image.h"
#include "string"
#include<map>


class Texture
{
    public:
        static Texture* Getinstance()
    {
        return instance = (instance != nullptr)? instance: new Texture();
    }

    bool Load(std::string id, std::string filename); // loads needed texture
    void Drop(std::string id);                       // offloads texture when no longer needed
    void Clean();                                    // destroys texture pointers
    void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip= SDL_FLIP_NONE );
    void DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip= SDL_FLIP_NONE );



    private:
         Texture() {}
    std::map<std::string, SDL_Texture*> Texturemap;   //use to store textures loaded
    static Texture* instance;
};

#endif // TEXTURE_H
