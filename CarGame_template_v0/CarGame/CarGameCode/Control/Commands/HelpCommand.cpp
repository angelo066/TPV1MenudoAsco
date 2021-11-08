#include "HelpCommand.h"
#include "..//..//Logic/Game.h"

bool HelpCommand::parse(SDL_Event& event)
{
	if (event.key.keysym.sym == SDLK_h) {
		help = true;
		return true;
	}

	if (event.key.keysym.sym == SDLK_j) {
		help = false;
		return true;
	}

	return false;
}

void HelpCommand::execute()
{
	if (game->getState() == Menu && help)
		game->changeState(Help);
	else if(game->getState() == Help && !help)
		game->changeState(Menu);
}
