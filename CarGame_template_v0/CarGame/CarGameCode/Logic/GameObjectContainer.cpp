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
	for (int i = 0; i < gameObjects.size(); i++) {
		if (gameObjects[i]->toDelete()) {
			gameObjects[i]->onDelete();

			delete gameObjects[i];
			gameObjects.erase(gameObjects.begin() + i);
		}
	}
}

bool GameObjectContainer::hasCollision(GameObject* g)
{
	if(getCollisions(g).size() == 0)return false;

	return true;
}

vector<Collider*> GameObjectContainer::getCollisions(GameObject* g)
{
	vector<Collider*>colliders;

	for (auto gO : gameObjects) {
		if (SDL_HasIntersection(&g->getCollider(), &gO->getCollider()))
			colliders.push_back(gO);
	}

	return colliders;
}
