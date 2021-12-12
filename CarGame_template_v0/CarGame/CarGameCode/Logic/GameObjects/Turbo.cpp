#include "Turbo.h"
#include "..//Game.h"

Turbo::Turbo(Game* g, double x, double y, int w_, int h_) : GoodObject(g)
{
	Car* player = game->getCar();

	setPosition(x - player->getX(), y - player->getY());
	setDimension(w_, h_);
}

Turbo::~Turbo()
{

}

void Turbo::draw()
{
	drawTexture(game->getTexture(turboTexture));
}

void Turbo::drawDebug()
{
	Box(getCollider(), TURBO).render(game->getRenderer());
}

bool Turbo::receiveCarCollision(Car* car)
{
	car->setTurbo();

	return true;
}
