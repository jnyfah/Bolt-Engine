#ifndef ENGINE_H
#define ENGINE_H
#include"SDL.h"
#include "SDL_image.h"
#include "GameMap.h"

const int screen_width =940;
const int screen_height =640;
class Engine
{
    public:

        inline static Engine* Get_instance()
        {
            if(instance != nullptr)
            {
                return instance;
            }
            else
            {
                return instance = new Engine();
            }
        }


        bool Init();
        void Clean();
        void Quit();

        void Update();
        void Render();
        void Events();

        inline bool isRunning()
        {
            return status;
        }

        inline SDL_Renderer* Get_Renderer()
        {
            return render;
        }

        inline GameMap* GetMap()
        {
            return levelmap;
        }

    private:
        Engine(){}
        static Engine* instance;
        bool status;
        SDL_Window* window;
        SDL_Renderer* render;

        GameMap* levelmap;

};

#endif // ENGINE_H
