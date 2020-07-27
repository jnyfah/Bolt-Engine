#include <iostream>
#include "Timer.h"
#include "Engine.h"
#include "SDL.h"

using namespace std;

int main(int argc, char** argv)
{


    Engine::Get_instance()->Init();

    while(Engine::Get_instance()->isRunning())
    {

        Engine::Get_instance()->Events();
        Engine::Get_instance()->Update();
        Engine::Get_instance()->Render();
        Timer::Get_Instance()->Tick();

    }

    Engine::Get_instance()->Clean();
    return 0;
}
