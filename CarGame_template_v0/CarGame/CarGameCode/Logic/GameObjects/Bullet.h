#pragma once
#include "GooObject.h"


class Bullet : public GoodObject
{
	const float bulletSpeed = 15;

public:
	Bullet(Game* gam, double x = 0, double y = 0, int w_ = 50, int h_ = 50);
	~Bullet();

	void collidedWithSomthing();

private:
	//Para saber donde empieza
	float initPos;


	virtual void update();

	// Heredado vía GoodObject
	virtual void draw() override;
	virtual void drawDebug();

};