#include "HelpCommand.h"
#include "..//..//Logic/Game.h"

bool HelpCommand::parse(SDL_Event& event)
{
	if (event.key.keysym.sym == SDLK_h && 
		event.type == SDL_KEYDOWN) {
		return true;
	}

	return false;
}

void HelpCommand::execute()
{
	game->setHelp(!game->getHelp());
}
