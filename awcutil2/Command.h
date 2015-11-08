#pragma once

namespace awcutil
{

	class Command
	{
	public:
		virtual ~Command() {}
		virtual void execute() = 0;
	};

}
