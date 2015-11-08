
#include <iostream>
#include <SDL.h>
#undef main
#include <awcutil.h>

#define _USE_MATH_DEFINES
#include <math.h>

using std::cout;

using awcutil::Vector2f;

using awcutil::clamp;
using awcutil::approach;
using awcutil::deg2rad;
using awcutil::rad2deg;
using awcutil::dsin;
using awcutil::dcos;
using awcutil::angd_normalize;
using awcutil::angd_difference;
using awcutil::angd_approach;
using awcutil::angd_forward;
using awcutil::angr_normalize;
using awcutil::angr_difference;
using awcutil::angr_approach;
using awcutil::angr_forward;

using awcutil::sdl::Window;
using awcutil::sdl::EventContainer;

int main(int argc, char* args[])
{
	//cout << angr_normalize((float)M_PI);
	Window window("Hi", 640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);

	bool run = true;

	EventContainer events;

	while (run)
	{
		events.think();
		if (events.has_event_type(SDL_QUIT))
		{
			run = false;
		}

		//SDL_SetRenderDrawColor(window.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(window.renderer);
		//Render present
		SDL_RenderPresent(window.renderer);
	}

	return 0;
}
