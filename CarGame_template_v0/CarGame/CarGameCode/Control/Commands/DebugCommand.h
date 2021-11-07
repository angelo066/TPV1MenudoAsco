#pragma once
#include "Command.h"

class DebugCommand : public Command
{
private:
	bool debug = false;
public:
	const string INFO_STRING = "q to Debug <-, e to stop Debug";

	DebugCommand() {
		info_string = INFO_STRING;
	};
	~DebugCommand() = default;
	bool parse(SDL_Event& event) override;
	void execute() override;

};
