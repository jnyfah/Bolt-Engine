#include <iostream>
#include "SDL.h"
#include "Engine.h"

using namespace std;

int main(int argc, char** argv)
{
    Engine::Get_instance()->Init();

    while(Engine::Get_instance()->isRunning())
    {

        Engine::Get_instance()->Events();
        Engine::Get_instance()->Update();
        Engine::Get_instance()->Render();

    }

    Engine::Get_instance()->Clean();
    return 0;
}
