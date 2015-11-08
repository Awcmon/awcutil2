#include "EventContainer.h"

namespace awcutil
{
	namespace sdl
	{
		EventContainer::EventContainer()
		{

		}

		EventContainer::~EventContainer()
		{

		}



		void EventContainer::think()
		{
			events.clear();
			while (SDL_PollEvent(&e) != 0)
			{
				events.push_back(e);
			}
		}

		bool EventContainer::has_event_type(int ev)
		{
			for (int i = 0; i < (int)events.size(); i++)
			{
				if (events[i].type == ev)
				{
					return true;
				}
			}
			return false;
		}
	}
}
