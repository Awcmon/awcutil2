#pragma once

#include <map>
#include <vector>
#include "Command.h"
#include <SDL.h>

using std::map;
using std::vector;

namespace awcutil
{
	namespace sdl
	{
		class EventContainer
		{
		public:
			EventContainer();
			~EventContainer();

			vector<SDL_Event> get_events();

			void think();

			bool EventContainer::has_event_type(int ev);

		private:
			SDL_Event e;	//Temp place to store events.
			vector<SDL_Event> events;
		};

	}
}
