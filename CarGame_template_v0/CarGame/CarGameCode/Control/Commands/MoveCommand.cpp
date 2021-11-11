#include "MoveCommand.h"
#include "..//..//Logic/Game.h"

bool MoveCommand::parse(SDL_Event& event)
{
	//Comprobamos que son las flechas
	//Luego ya comprobamos si están pulsando o levantando
	if (event.key.keysym.sym == SDLK_UP ||
		event.key.keysym.sym == SDLK_DOWN) {

		if (event.type == SDL_KEYDOWN)  {
			mUp = event.key.keysym.sym == SDLK_UP;

			mDown = event.key.keysym.sym == SDLK_DOWN;

			return true;
		}
		else if (event.type == SDL_KEYUP) {
			mUp = false;

			mDown = false;

			return true;
		}

	}

	return false;
}

void MoveCommand::execute()
{
	//Si va arriba o abajo
	if (mUp || mDown)
		game->moveCar(mUp);
	else game->stopCar();

}
