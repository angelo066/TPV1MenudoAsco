#pragma once

#include "Command.h"
#include "..//..//Logic/GameObjects/Bullet.h"

class ShootCommand : public Command
{
	const int w = 20;
	const int h = 5;

private:
	bool accelerate = true;

public:
	const string INFO_STRING = "Press s to shoot";

	ShootCommand() {
		info_string = INFO_STRING;
	};
	~ShootCommand() = default;
	bool parse(SDL_Event& event) override;
	void execute() override;
};