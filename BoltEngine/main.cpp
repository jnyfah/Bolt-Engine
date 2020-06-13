#include <iostream>
#include "SDL.h"
#include "Engine.h"



int main(int argc, char** argv)
{
    Engine::Getinstance()->Init();

    while(Engine::Getinstance()->is_Running())
    {
        Engine::Getinstance()->Events();

        Engine::Getinstance()->Update();

        Engine::Getinstance()->Render();
    }

    Engine::Getinstance()->Clean();

    return 0;
}
