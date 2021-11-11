#include "StartCommand.h"
#include "..//..//Logic/Game.h"

bool StartCommand::parse(SDL_Event& event)
{
	if (event.key.keysym.sym == SDLK_SPACE &&
		event.type == SDL_KEYDOWN) {
		return true;
	}

	return false;
}

void StartCommand::execute()
{
	if(game->getState() == Menu)game->changeState(Playing);
	else if (game->getState() == Gameover) {
		game->resetGame();
		game->changeState(Playing);
	}
}
