#pragma once
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "Car.h"
#include "BadObject.h"
#include "Bullet.h"

class Game;

class Wall :public BadObject{

public:
	Wall(Game* gam, double x = 0, double y = 0, int w_ = 50, int h_ = 50);

	virtual void update();
	virtual void draw();
	virtual void drawDebug();

	virtual SDL_Rect getCollider();

	virtual bool receiveCarCollision(Car* car);

	virtual bool receiveBulletCollision(Bullet *bullet);
};
