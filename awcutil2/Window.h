#pragma once

#include <SDL.h>
#include <string>

using std::string;

namespace awcutil
{
	namespace sdl
	{
		class Window
		{
		public:
			Window();
			Window(string _name, int _w, int _h, Uint32 _flags);
			~Window();
		private:
			SDL_Window* window;
			SDL_Renderer* renderer;
			string name;
			int w;
			int h;
			Uint32 flags;
		};

	}
}


