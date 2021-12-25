#pragma once

#include "BadObject.h"

class Game;

class Truck : public BadObject
{
public:
	Truck(Game* g, double x = 0,
		double y = 0, int w_ = 120, int h_ = 60);

	~Truck();

private:
	const int vel = 5;
	// Heredado vía BadObject
	virtual void draw() override;
	virtual void update();
	virtual void drawDebug();

	virtual SDL_Rect getCollider();

	virtual bool receiveCarCollision(Car* car);

	virtual bool receiveBulletCollision(Bullet* bullet);
};