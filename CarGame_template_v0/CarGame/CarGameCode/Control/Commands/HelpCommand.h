#pragma once

#include "Command.h"

class HelpCommand : public Command
{
private:

public:
	const string INFO_STRING = "Press H for help press again to hide help";

	HelpCommand() {
		info_string = INFO_STRING;
	};
	~HelpCommand() = default;
	bool parse(SDL_Event& event) override;
	void execute() override;

};