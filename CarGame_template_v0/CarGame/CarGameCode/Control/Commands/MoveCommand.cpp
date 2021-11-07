#include "MoveCommand.h"
#include "..//..//Logic/Game.h"

bool MoveCommand::parse(SDL_Event& event)
{
	if (event.key.keysym.sym == SDLK_UP) {
		up = true;
		return true;
	}

	if (event.key.keysym.sym == SDLK_DOWN) {
		up = false;
		return true;
	}

	return false;
}

void MoveCommand::execute()
{
	game->moveCar(up);

	bool isOver = game->getState() == Gameover;

	if (game->getState() == Menu ||
		isOver) game->changeState(Playing);


	if (isOver) game->resetGame();
}
