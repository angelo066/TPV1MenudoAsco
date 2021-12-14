#pragma once
#include "BadObject.h"

class Game;

class SuperRock : public BadObject
{
public:
	SuperRock(Game* g, double x = 0,
		double y = 0, int w_ = 160, int h_ = 80);

	~SuperRock();

private:
	// Heredado vía BadObject
	virtual void draw() override;
	virtual void update();
	virtual void drawDebug();

	virtual SDL_Rect getCollider();

	virtual bool receiveCarCollision(Car* car);
};
