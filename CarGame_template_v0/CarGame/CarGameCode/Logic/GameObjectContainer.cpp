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

bool GameObjectContainer::hasCollision(GameObject* g)
{
	return false;
}

vector<Collider*> GameObjectContainer::getCollisions(GameObject* g)
{
	vector<Collider*>colliders;

	

	return colliders;
}
