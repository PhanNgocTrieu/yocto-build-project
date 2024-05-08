#include "Application.h"

Application* Application::getInstance() {
    static Application _ins;
    return &_ins;
}

bool Application::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "init sdl failed: %s\n", SDL_GetError());
    }

    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		fprintf(stderr, "Unable to Init hinting: %s", SDL_GetError());
	}

    if( (Window = SDL_CreateWindow(
		"My SDL Game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		640, 400, SDL_WINDOW_SHOWN)
    ) == nullptr) {
		fprintf(stderr, "Unable to create SDL Window: %s\n", SDL_GetError());
		return false;
	}

    PrimarySurface = SDL_GetWindowSurface(Window);

#if 0
    if((Renderer = SDL_CreateRenderer(Window, -1, 0)) == NULL) {
	    fprintf(stderr, "Unable to create renderer\n");
	    return false;
	}

	SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0xFF);

	// Initialize image loading for PNGs
	if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		fprintf(stderr, "Unable to init SDL_image: %s", IMG_GetError());
		return false;
	}
	// Load all of our Textures (see TextureBank class for expected folder)
	if(TextureBank::Init() == false) {
		Log("Unable to init TextureBank");
		return false;
	}
#endif
	return true;
}

int Application::execute(int argc, char* argv[]) {
    if (!m_isRunning) {
        fprintf(stderr, "execute application failed due to not initialized\n");
        return -1;
    }

    SDL_Event _event;

    while(m_isRunning) {
        while(SDL_PollEvent(&_event) != 0) {
			eventHandle(_event);
		}
        loop();
        render();
        SDL_Delay(1);
    }
    clean();
    return 0;
}

Application::Application() {
    m_isRunning = init();
}

void Application::eventHandle(SDL_Event e) {
    switch (e.type)
    {
        case SDL_EventType::SDL_QUIT: {
            m_isRunning = false;
            break;
        }
        default: {
            break;
        }
    }
}

void Application::loop() {

}

void Application::render() {

}

void Application::clean() {
    if (Window) {
        Window = nullptr;
    }

    if (Renderer) {
        Renderer = nullptr;
    }

    if (PrimarySurface) {
        PrimarySurface = nullptr;
    }
    SDL_Quit();
}
