#pragma once
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "Car.h"

class Game;

class Wall {

private:

	int w;
	int h;
	Point2D<double> pos;
	Game* g;
	Car* player;

public:
	Wall(Game* gam, Car* p, double x, double y, int w_, int h_);

	void update();
	void draw();
	void drawTexture(Texture* texture);

	Point2D<double> getPos() { return pos; }
	void setPos(double newX) { pos.setX(newX); }

	SDL_Rect getRect();
};
