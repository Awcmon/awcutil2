#pragma once

#include <map>
#include "Command.h"

using std::map;

namespace awcutil
{
	namespace sdl
	{
		class Keyboard
		{
		public:
			Keyboard();
			~Keyboard();

			map<int, Command*> command_map;
		};

	}
}