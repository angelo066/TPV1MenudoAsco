#pragma once
#include "GooObject.h"
class Hearth : public GoodObject
{
public:
	Hearth(Game* gam, double x = 0, double y = 0, int w_ = 50, int h_ = 50);

	virtual void draw();
	virtual void drawDebug();

	virtual bool receiveCarCollision(Car* car);
};

