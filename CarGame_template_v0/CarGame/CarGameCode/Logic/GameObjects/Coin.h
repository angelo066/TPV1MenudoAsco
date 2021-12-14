#pragma once
#include "GooObject.h"

class Game;

class Coin : public GoodObject
{

public:
	Coin(Game* gam, double x = 0, double y = 0, int w_ = 20, int h_ = 20);
	~Coin();

private:

	// Heredado vía GoodObject
	virtual void draw() override;
	virtual void drawDebug();

	virtual bool receiveCarCollision(Car* car);
};