#include "Event.h"
#include "../Engine.h"

Event* Event::Instance = nullptr;
void Event::Listen()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
        case SDL_QUIT:
            Engine::Get_instance()->Quit();
            break;
        case SDL_KEYDOWN:
            Key_Down();
            break;
        case SDL_KEYUP:
            Key_Up();
            break;
        }
    }
}

bool Event::Get_KeyDown(SDL_Scancode key)
{
   if (keystate[key] ==1)
   {
       return true;
   }else
   return false;
}

Event::Event()
{
keystate = SDL_GetKeyboardState(nullptr);
}

void Event::Key_Down()
{
keystate = SDL_GetKeyboardState(nullptr);
}

void Event::Key_Up()
{
  keystate = SDL_GetKeyboardState(nullptr);
}
