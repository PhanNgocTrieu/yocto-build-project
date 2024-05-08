#include "window.h"

Window::Window() {}

SDL_Window* Window::generate_window(const char* _tt,
            int _x,
            int _y,
            int _w,
            int _h,
            Uint32 _flg) {
    m_window = SDL_CreateWindow(_tt, _x, _y, _w, _h, _flg);
    return m_window;
}