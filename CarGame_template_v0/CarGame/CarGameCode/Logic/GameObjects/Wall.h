#pragma once
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "Car.h"
#include "BadObject.h"

class Game;

class Wall : BadObject{

private:

	Car* player;

public:
	Wall(Game* gam, Car* p = nullptr, double x = 0, double y = 0, int w_ = 50, int h_ = 50);

	void update();
	void draw();
	void drawTexture(Texture* texture);

	virtual SDL_Rect getCollider();
};
