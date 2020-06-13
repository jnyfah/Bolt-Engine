#include "Engine.h"
#include "Texture.h"
#include <iostream>


Engine* Engine::s_instance = nullptr;

bool Engine::Init()
{
  if (SDL_Init(SDL_INIT_VIDEO) !=0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
  {
      SDL_Log(" Failed to initialize SDL: %s", SDL_GetError());
      return false;
  }

  window = SDL_CreateWindow("Bolt-Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

  if(window == nullptr)
  {
      SDL_Log("Failed to create window: %s", SDL_GetError());
      return false;
  }


  Texture::Getinstance()->Load("tree", "assets/test.png");
  return Running_status =true ;
}

bool Engine::Clean()
{

}

void Engine::Quit()
{
   Running_status = false;
}

void Engine::Update()
{
  std::cout<<"updating"<<std::endl;
}

void Engine::Render()
{
  SDL_SetRenderDrawColor(renderer, 124, 218, 254, 255);
  SDL_RenderClear(renderer);

  Texture::Getinstance()->Draw("tree", 100, 100, 1024, 600);
  SDL_RenderPresent(renderer);
}

void Engine::Events()
{
   SDL_Event event;
   SDL_PollEvent(&event);
   switch(event.type)
   {
   case SDL_QUIT:
     Quit();
   }

}


Engine::~Engine()
{
    //dtor
}
