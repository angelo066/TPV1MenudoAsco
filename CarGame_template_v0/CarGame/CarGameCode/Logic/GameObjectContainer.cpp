#include "GameObjectContainer.h"

GameObjectContainer::~GameObjectContainer()
{
	for (auto gO : gameObjects) {
		delete gO;
	}
	gameObjects.clear();
}

void GameObjectContainer::update()
{
	for (auto gO : gameObjects) {
		gO->update();
	}
}

void GameObjectContainer::draw()
{
	for (auto gO : gameObjects) {
		gO->draw();
	}
}

void GameObjectContainer::add(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}

void GameObjectContainer::removeDead()
{
	for (auto gO : gameObjects) {
		if (gO->toDelete()) {
			delete gO;
			//gameObjects.erase(gO);
		}
	}
}

bool GameObjectContainer::hasCollision(GameObject* g)
{
	if(getCollisions(g).size() == 0)return false;

	return true;
}

//? Esto no me deberia devolver una lista de GameObjects?
vector<Collider*> GameObjectContainer::getCollisions(GameObject* g)
{
	vector<Collider*>colliders;

	for (auto gO : gameObjects) {
		if (SDL_HasIntersection(&g->getCollider(), &gO->getCollider()))
			colliders.push_back(gO);
	}

	return colliders;
}
