#include "hearth.h"
#include "..//Game.h"

Hearth::Hearth(Game* gam, double x, double y, int w_, int h_) : GoodObject(gam)
{
	Car* player = game->getCar();

	setPosition(x - player->getX(), y - player->getY());
	setDimension(w_, h_);
}

void Hearth::draw()
{
	drawTexture(game->getTexture(hearthTexture));
}

void Hearth::drawDebug()
{
	Box(getCollider(), BLACK).render(game->getRenderer());
}

bool Hearth::receiveCarCollision(Car* car)
{
	game->heal(1);

	alive = false;

	return true;
}
