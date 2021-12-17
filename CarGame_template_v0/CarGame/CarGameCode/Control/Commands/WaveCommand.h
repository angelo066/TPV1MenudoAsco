#pragma once

#include "Command.h"

class WaveCommand : public Command
{
private:
	bool accelerate = true;

public:
	const string INFO_STRING = "Press W to use the wave";

	WaveCommand() {
		info_string = INFO_STRING;
	};
	~WaveCommand() = default;
	bool parse(SDL_Event& event) override;
	void execute() override;

};
