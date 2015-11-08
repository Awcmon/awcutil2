#include "Window.h"

namespace awcutil
{
	namespace sdl
	{

		Window::Window()
		{
			name = "";
			w = 640;
			h = 480;
			flags = 0;
			SDL_Init(SDL_INIT_EVERYTHING);

			window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		}

		Window::Window(string _name, int _w, int _h, Uint32 _flags)
		{
			name = _name;
			w = _w;
			h = _h;
			flags = _flags;
			SDL_Init(SDL_INIT_EVERYTHING);

			window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		}

		Window::~Window()
		{
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			renderer = NULL;
			window = NULL;
			SDL_Quit();
		}

	}
}
