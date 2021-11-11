#include "AccCommand.h"
#include "..//..//Logic/Game.h"

bool AccCommand::parse(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN) {

		if (event.key.keysym.sym == SDLK_RIGHT) {
			accelerate = true;
			return true;
		}

		if (event.key.keysym.sym == SDLK_LEFT) {
			accelerate = false;
			return true;
		}
	}

	return false;
}

void AccCommand::execute()
{
	game->acelerateCar(accelerate);

	bool isOver = game->getState() == Gameover;

	if (game->getState() == Menu ||
		isOver) game->changeState(Playing);


	if (isOver) game->resetGame();

}
