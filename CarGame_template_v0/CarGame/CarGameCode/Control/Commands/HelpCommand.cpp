#include "HelpCommand.h"
#include "..//..//Logic/Game.h"

bool HelpCommand::parse(SDL_Event& event)
{
	if (event.key.keysym.sym == SDLK_h) {
		return true;
	}

	return false;
}

void HelpCommand::execute()
{
	game->setHelp(!game->getHelp());
}
