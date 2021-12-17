#pragma once
#include "BadObject.h"

class Game;

class Oil : public BadObject
{
public:
	Oil(Game* g, double x = 0,
		double y = 0, int w_ = 40, int h_ = 40);

	~Oil();

private:
	// Heredado vía BadObject
	virtual void draw() override;
	virtual void update();
	virtual void drawDebug();

	virtual SDL_Rect getCollider();

	virtual bool receiveCarCollision(Car* car);
};