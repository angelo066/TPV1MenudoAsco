#include "Coin.h"
#include "..//Game.h"

Coin::Coin(Game* gam, double x,
	double y, int w_, int h_) : GoodObject(gam)
{
	Car* player = game->getCar();

	setPosition(x - player->getX(), y - player->getY());
	setDimension(w_, h_);
}

Coin::~Coin()
{

}

void Coin::draw()
{
	drawTexture(game->getTexture(coinTexture));
}

void Coin::drawDebug()
{
	Box(getCollider(), BLACK).render(game->getRenderer());
}


bool Coin::receiveCarCollision(Car* car)
{
	game->addCoin();

	alive = false;

	return true;
}
