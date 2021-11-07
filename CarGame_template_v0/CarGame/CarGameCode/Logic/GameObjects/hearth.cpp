#include "hearth.h"
#include "..//Game.h"

Hearth::Hearth(Game* gam, double x, double y, int w_, int h_) : GoodObject(gam)
{
	Car* player = game->getCar();

	setPosition(x - player->getX(), y - player->getY());
	setDimension(w_, h_);
}

void Hearth::update()
{
	setPosition(getX() - game->getCar()->getHorizontalV(),
		getY());

}

void Hearth::draw()
{
	drawTexture(game->getTexture(hearthTexture));
}

void Hearth::drawDebug()
{
	Box(getCollider(), BLACK).render(game->getRenderer());
}

SDL_Rect Hearth::getCollider()
{
	return { int(getX()),
	  int(getY()), //Por que /2?
	  getWidth(),						//Porque le pone 1/2 arri. y otro abajo?
	  getHeight() };
}

bool Hearth::receiveCarCollision(Car* car)
{
	game->heal(1);

	alive = false;

	return true;
}
