#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Window {
    public:
        Window();

        virtual ~Window() {}
        SDL_Window* generate_window(const char* _tt,
            int _x = SDL_WINDOWPOS_UNDEFINED,
            int _y = SDL_WINDOWPOS_UNDEFINED,
            int _w = 640,
            int _h = 400,
            Uint32 _flg = SDL_WINDOW_SHOWN
        );
    
    protected:
        SDL_Window* m_window = nullptr;

};

#endif