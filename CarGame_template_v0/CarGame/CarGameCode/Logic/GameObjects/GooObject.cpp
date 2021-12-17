#include "GooObject.h"
#include "..//Game.h"

void GoodObject::update()
{
	setPosition(getX() - game->getCar()->getHorizontalV(),
		getY());
}

bool GoodObject::toDelete()
{
	return !alive || game->isRebased(this);
}

void GoodObject::onEnter()
{
	instances += 1;
}

void GoodObject::onDelete()
{
	instances -= 1;
}

void GoodObject::reset()
{
	instances = 0;
}

SDL_Rect GoodObject::getCollider()
{
	return { int(getX()),
		int(getY()), //Por que /2?
		getWidth(),						//Porque le pone 1/2 arri. y otro abajo?
		getHeight() };
}

void GoodObject::receiveWave()
{
	setPosition(getX() - waveEffect, getY());
}

int GoodObject::instances = 0;