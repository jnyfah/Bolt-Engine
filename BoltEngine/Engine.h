#ifndef ENGINE_H
#define ENGINE_H
#include "SDL.h"
#include "SDL_image.h"


const int SCREEN_WIDTH = 950;
const int SCREEN_HEIGHT = 640;


class Engine
{
public:

    static Engine* Getinstance()
    {
        return s_instance = (s_instance != nullptr)? s_instance: new Engine();
    }

    bool Init();
    bool Clean();
    void Quit();

    void Update();
    void Render();
    void Events();

    inline bool is_Running()
    {
        return Running_status;
    }

    inline SDL_Renderer *Get_renderer()
    {
        return renderer;
    }
    virtual ~Engine();



private:
    Engine(){} //constructor is private because it is a simpleton class

    static Engine* s_instance;
    SDL_Window * window;
    SDL_Renderer *renderer;
    bool Running_status;
};

#endif // ENGINE_H
