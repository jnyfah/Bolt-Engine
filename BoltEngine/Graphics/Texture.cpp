#include "Texture.h"

#include "../Engine.h"


Texture* Texture::instance = nullptr;

bool Texture::Load(std::string id, std::string filename)
{
    SDL_Surface *surface = IMG_Load(filename.c_str());
    if (surface == nullptr)
    {
        SDL_Log(" failed to load surface: %s", SDL_GetError());
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::Get_instance()->Get_Renderer(), surface);
    if (texture == nullptr)
    {
        SDL_Log(" failed to load texture: %s", SDL_GetError());
        return false;
    }

    Texturemap[id]= texture;
    return true;

}


void Texture::Drop(std::string id)
{
    SDL_DestroyTexture(Texturemap[id]);
    Texturemap.erase(id);
}

void Texture::Clean()
{
  std::map<std::string,  SDL_Texture*>::iterator it;

  for(it = Texturemap.begin(); it!= Texturemap.end(); it++)
  {
      SDL_DestroyTexture(it->second);

  }
  Texturemap.clear();
  SDL_Log("texture map cleaned!");
}

void Texture::Draw(std::string id, int x, int y, int width, int hgt, SDL_RendererFlip flip)
{
    SDL_Rect src_rect = {0, 0,width, hgt};
    SDL_Rect dst_rect = {x, y, width, hgt};
    SDL_RenderCopyEx(Engine::Get_instance()->Get_Renderer(), Texturemap[id], &src_rect, &dst_rect, 0, nullptr, flip);

}

void Texture::DrawFrame(std::string id, int x, int y, int width, int hgt, int row, int frame,  SDL_RendererFlip flip)
{
    SDL_Rect src_rect = {width*frame, hgt*(row-1), width, hgt};
    SDL_Rect dst_rect = {x, y, width, hgt};
    SDL_RenderCopyEx(Engine::Get_instance()->Get_Renderer(), Texturemap[id], &src_rect, &dst_rect, 0, nullptr, flip);

}



