#pragma once

#include <map>
#include "Command.h"

using std::map;

namespace awcutil
{
	namespace sdl
	{
		class EventHandler
		{
		public:
			EventHandler();
			~EventHandler();

			map<int, Command*> command_map;
		};

	}
}