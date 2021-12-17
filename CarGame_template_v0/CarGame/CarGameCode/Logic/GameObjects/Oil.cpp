#include "Oil.h"
#include "..//Game.h"


Oil::Oil(Game* g, double x, double y, int w_, int h_) : BadObject(g)
{
	Car* player = game->getCar();

	setPosition(x - player->getX(), y - player->getY());
	setDimension(w_, h_);
}

Oil::~Oil()
{

}

void Oil::draw()
{
	drawTexture(game->getTexture(oilTexture));
}

void Oil::update()
{
	setPosition(getX() - game->getCar()->getHorizontalV(),
		getY());
}

void Oil::drawDebug()
{
	Box(getCollider(), OIL).render(game->getRenderer());
}

SDL_Rect Oil::getCollider()
{
	return { int(getX()),
  int(getY()), //Por que /2?
  getWidth(),						//Porque le pone 1/2 arri. y otro abajo?
  getHeight() };
}

bool Oil::receiveCarCollision(Car* car)
{
	car->setOil();

	return true;
}
