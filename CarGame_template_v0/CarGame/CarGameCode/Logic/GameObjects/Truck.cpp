#include "Truck.h"
#include "..//Game.h"

Truck::Truck(Game* g, double x, double y, int w_, int h_) : BadObject(g)
{
	Car* player = game->getCar();

	setPosition(x - player->getX(), y - player->getY());
	setDimension(w_, h_);
}

Truck::~Truck()
{

}

void Truck::draw()
{
	drawTexture(game->getTexture(truckTexture));
}

void Truck::update()
{
	setPosition(getX() - game->getCar()->getHorizontalV() - vel,
		getY());
}

void Truck::drawDebug()
{
	Box(getCollider(), TRUCK).render(game->getRenderer());
}

SDL_Rect Truck::getCollider()
{
	return { int(getX()),
	int(getY()), //Por que /2?
	getWidth(),						//Porque le pone 1/2 arri. y otro abajo?
	getHeight() };
}

bool Truck::receiveCarCollision(Car* car)
{
	alive = false;

	game->receiveDmg(1);

	car->resetVelocity();

	return true;
}

bool Truck::receiveBulletCollision(Bullet* bullet)
{
	alive = false;

	return true;
}
