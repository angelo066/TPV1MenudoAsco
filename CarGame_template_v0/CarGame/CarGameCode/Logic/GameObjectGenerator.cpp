#include "GameObjectGenerator.h"
#include "Game.h"

Point2D<int> GameObjectGenerator::generateRandomPosition(Game* game, GameObject* o)
{
	float inferiorLimit = game->getWindowHeight() - o->getHeight();

	double x = rand() % (int)game->getRoadL() + 300;
	double y = rand() % (int)inferiorLimit + 0;

	Point2D<int> randPos(x,y);

	return randPos;
}

void GameObjectGenerator::addInRandomPosition(Game* game, GameObject* o)
{
	Point2D<int> randPos = generateRandomPosition(game, o);

	o->setPosition(randPos.getX(), randPos.getY());

	//! Si no está ocupado, lo ponemos
	if (!game->pointOcuppied(o)) {
		game->addGameObject(o);
		o->onEnter();
	}
	else delete o;
}

void GameObjectGenerator::randomPowerUp(Game* g)
{
	if (g->random(0, 2)) {
		addInRandomPosition(g, new Hearth(g));
	}
}
