#ifndef APPLICATION_H
#define APPLICATION_H

#include "window.h"

class Application {
    public:
        static Application* getInstance();
        int execute(int argc, char* argv[]);

    protected:
        Application();
        bool init();
        void loop();
        void render();
        void clean();
        void eventHandle(SDL_Event e);
    
    protected:
        SDL_Window* Window = nullptr;
		SDL_Renderer* Renderer = nullptr;
		SDL_Surface* PrimarySurface = nullptr;
        bool m_isRunning{false};
};

#endif // APPLICATION_H