#pragma once
#include "Command.h"

class MoveCommand : public Command
{
private: 
	bool mUp, mDown;
public:
	const string INFO_STRING = "Up Arrow to go up Down arrow to go Down";

	MoveCommand() {
		info_string = INFO_STRING;
	};
	~MoveCommand() = default;
	bool parse(SDL_Event& event) override;
	void execute() override;
};