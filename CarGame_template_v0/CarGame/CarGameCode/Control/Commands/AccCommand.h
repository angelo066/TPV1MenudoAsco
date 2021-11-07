#pragma once
#ifndef CARGAME_ACCCOMMAND_H
#define CARGAME_ACCCOMMAND_H

#include "Command.h"

class AccCommand : public Command
{
private:
	bool accelerate = true;

public:
	const string INFO_STRING = "-> to Accelerate <- to decelerate";

	AccCommand() {
		info_string = INFO_STRING;
	};
	~AccCommand() = default;
	bool parse(SDL_Event& event) override;
	void execute() override;

};
#endif //CARGAME_ACCCOMMAND_H