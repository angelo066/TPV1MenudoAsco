#pragma once

#include "Command.h"

class StartCommand : public Command
{
private:
	bool mUp, mDown;
public:
	const string INFO_STRING = "Press space to start the game";

	StartCommand() {
		info_string = INFO_STRING;
	};
	~StartCommand() = default;
	bool parse(SDL_Event& event) override;
	void execute() override;
};