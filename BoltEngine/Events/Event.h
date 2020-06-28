#ifndef EVENT_H
#define EVENT_H

#include "SDL.h"


class Event
{
    public:
        static Event *Get_Instance()
        {
            if(Instance == nullptr)
            {
                Instance = new Event;
            }

            return Instance;
        }

        void Listen();
        bool Get_KeyDown(SDL_Scancode key);



    private:
         Event();
         static Event *Instance;
        void Key_Down();
        void Key_Up();

        const Uint8 *keystate;
};

#endif // EVENT_H
