#include "SuperRock.h"
#include "..//Game.h"


SuperRock::SuperRock(Game* g, double x,
	double y, int w_, int h_) : BadObject(g)
{
	Car* player = game->getCar();

	setPosition(x - player->getX(), y - player->getY());
	setDimension(w_, h_);
}

SuperRock::~SuperRock()
{

}


void SuperRock::draw()
{
	drawTexture(game->getTexture(superRockTexture));
}

void SuperRock::update()
{
	setPosition(getX() - game->getCar()->getHorizontalV(),
		getY());
}

void SuperRock::drawDebug()
{
	Box(getCollider(), SUPERRED).render(game->getRenderer());
}

SDL_Rect SuperRock::getCollider()
{
	return { int(getX()),
	  int(getY()), //Por que /2?
	  getWidth(),						//Porque le pone 1/2 arri. y otro abajo?
	  getHeight() };
}

bool SuperRock::receiveCarCollision(Car* car)
{
	alive = false;

	game->receiveDmg(2);

	car->resetVelocity();

	return true;
}
