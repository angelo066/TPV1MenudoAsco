#include "ShootCommand.h"
#include "..//..//Logic/Game.h"

bool ShootCommand::parse(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN) {

		if (event.key.keysym.sym == SDLK_s) {
			
			return true;
		}
	}

	return false;
}

void ShootCommand::execute()
{
	Car* c = game->getCar();

	if (game->getCoins() > 0) {
		game->addGameObject(new Bullet(game, 100, c->getY(), w, h));

		game->useCoin();
	}
}
