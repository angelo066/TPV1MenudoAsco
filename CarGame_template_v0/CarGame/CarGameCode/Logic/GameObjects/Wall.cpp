#include "Wall.h"
#include "..//Game.h"


Wall::Wall(Game* gam, double x, 
	double y, int w_, int h_) : BadObject(gam)
{
	Car* player = game->getCar();

	setPosition(x - player->getX(), y - player->getY());
	setDimension(w_, h_);
}

void Wall::update()
{
	//Para que se muevan
	setPosition(getX() - game->getCar()->getHorizontalV(),
		getY());
}

void Wall::draw()
{
	drawTexture(game->getTexture(rockTexture));
}

void Wall::drawDebug()
{
	Box(getCollider(), RED).render(game->getRenderer());
}

//getRect
SDL_Rect Wall::getCollider()
{	
	return { int(getX()),
		  int(getY()), //Por que /2?
		  getWidth(),						//Porque le pone 1/2 arri. y otro abajo?
		  getHeight() };
}

bool Wall::receiveCarCollision(Car* car)
{
	alive = false;

	game->receiveDmg(1);

	car->resetVelocity();

	return true;
}