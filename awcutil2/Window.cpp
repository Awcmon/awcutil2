#include "Window.h"

namespace awcutils
{
	namespace sdl
	{

		Window::Window()
		{
			name = "";
			SDL_Init(SDL_INIT_EVERYTHING);
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
