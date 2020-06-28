#include "Timer.h"
#include "SDL.h"


Timer *Timer::Instance = nullptr;

void Timer::Tick()
{
    m_deltatime = (SDL_GetTicks() - lasttime) * (TARGET_FPS/1000.0f);

    if(m_deltatime > TARGET_DELTA_TIME)
    {
        m_deltatime = TARGET_DELTA_TIME;
    }

    lasttime = SDL_GetTicks();
}


