#include "Engine.h"

#include "Warrior.h"
#include  "Texture.h"
#include "Event.h"
#include "Timer.h"
#include "SDL.h"
#include "MapParser.h"
#include "camera.h"



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



    if(!MapParser::Get_Instance()->load())
    {
        SDL_Log("failed to load map: %s", SDL_GetError());
    }

    levelmap = MapParser::Get_Instance()->Getmap("Level1");

    Texture::Getinstance()->Load("player", "assets/bandit1.png");
    Texture::Getinstance()->Load("player_run", "assets/bandit1run.png");
    Texture::Getinstance()->Load("player_jump", "assets/bandit1jump.png");
    Texture::Getinstance()->Load("background", "assets/plx-5.png");



    player = new Warrior(new Properties ("player", 48, 48, 136, 96));

    camera::Get_instance()->set_target(player->Get_origin());

    return status = true;


}

void Engine::Clean()
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
    float dt = Timer::Get_Instance()->Get_deltatime();

    player->Update(dt);
    levelmap->Update();
    camera::Get_instance()->Update(dt);
}

void Engine::Render()
{

    SDL_SetRenderDrawColor(render, 124, 218, 254, 255);

    SDL_RenderClear(render);



    Texture::Getinstance()->Draw("background", 0, 0, 2100, 1050);

    levelmap->Render();
    player->Draw();

    SDL_RenderPresent(render);

}

void Engine::Events()
{
    Event::Get_Instance()->Listen();
}
