#pragma once
#include "GooObject.h"

class Game;

class Turbo : public GoodObject
{
public:
	Turbo(Game* g,
		double x = 0, double y = 0, 
		int w_ = 80, int h_ = 40);
	~Turbo();

private:

	// Heredado vía GoodObject
	virtual void draw() override;
	virtual void drawDebug();

	virtual bool receiveCarCollision(Car* car);
};
