#include "Engine.h"
#include <iostream>
#include "Warrior.h"
#include  "Texture.h"




Engine *Engine::instance = nullptr;
Warrior* player = nullptr;


bool Engine::Init()
{
  if (SDL_Init(SDL_INIT_VIDEO != 0) && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) !=0)
  {
      SDL_Log("failed to initialize sdl: %s", SDL_GetError());
      return false;
  }

  window = SDL_CreateWindow("Bolt-Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, 0);
  if(window == nullptr)
    {
        SDL_Log("failed to create window: %s", SDL_GetError());
      return false;
    }

    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(render == nullptr)
    {
        SDL_Log("failed to create renderer: %s", SDL_GetError());
      return false;
    }

   Texture::Getinstance()->Load("player", "assets/knight walk animation.png");
   player = new Warrior(new Properties ("player", 30 , 40, 136, 96));

  return status = true;


}

bool Engine::Clean()
{
 Texture::Getinstance()->Clean();
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    IMG_Quit();
}

void Engine::Quit()
{
   status = false;
}

void Engine::Update()
{
   player->Update(0);
    //std::cout <<"updating.."<<std::endl;
}

void Engine::Render()
{
SDL_SetRenderDrawColor(render, 124, 218, 254, 255);
SDL_RenderClear(render);

//Texture::Getinstance()->Draw("player", 100, 100, 19, 34);

player->Draw();
SDL_RenderPresent(render);
}

void Engine::Events()
{
     SDL_Event event;
     SDL_PollEvent(&event);
     switch(event.type)
     {
     case SDL_QUIT:
        Quit();
        break;
     }
}
