#pragma once

#include <SDL.h>

#ifdef _AWCUTIL_OPENGL
#include <GL/glew.h>
#include <SDL_opengl.h>
#endif

#include <string>

#include <iostream>

using std::string;

namespace awcutil
{
	namespace sdl
	{
		class Window
		{
		public:
			Window() : Window("", 640, 480, 0) {};
			Window(string _name, int _w, int _h, Uint32 _flags)
			{
				name = _name;
				w = _w;
				h = _h;
				flags = _flags;
				SDL_Init(SDL_INIT_EVERYTHING);

#ifdef _AWCUTIL_OPENGL
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#endif

				window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);

#ifdef _AWCUTIL_OPENGL
				std::cout << "Using OpenGL renderer.\n";
				SDL_GLContext context = SDL_GL_CreateContext(window);

				glewExperimental = GL_TRUE;
				glewInit();
#else
				std::cout << "Using SDL renderer.\n";
				renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
#endif

			};
			~Window()
			{
#ifdef _AWCUTIL_OPENGL
				SDL_GL_DeleteContext(context);
#else
				SDL_DestroyRenderer(renderer);
				renderer = NULL;
#endif
				SDL_DestroyWindow(window);
				window = NULL;
				SDL_Quit();
			};
#ifdef _AWCUTIL_OPENGL
			SDL_GLContext context;
#else
			SDL_Renderer* renderer;
#endif
			SDL_Window* window;

		private:

			string name;
			int w;
			int h;
			Uint32 flags;
		};

	}
}


