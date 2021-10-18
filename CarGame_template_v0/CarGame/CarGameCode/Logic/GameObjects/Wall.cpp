#include "Wall.h"
#include "..//Game.h"


Wall::Wall(Game* gam, Car* p, double x, double y, int w_, int h_)
{
	g = gam;
	player = p;

	pos = Point2D<double>(x - player->getX(), y - player->getY());

	w = w_;
	h = h_;
}

void Wall::draw()
{
	drawTexture(g->getTexture(rockTexture));
}

//getRect
SDL_Rect Wall::getRect()
{	
	//Para que se muevan
	pos = Point2D<double>(pos.getX() - player->getHorizontalV(), 
		pos.getY());

	return { int(pos.getX()),
		  int(pos.getY()), //Por que /2?
		  w,						//Porque le pone 1/2 arri. y otro abajo?
		  h };
}

void Wall::drawTexture(Texture* texture)
{
	SDL_Rect c = getRect();
	SDL_Rect textureBox = { c.x, c.y, c.w, c.h };
	texture->render(textureBox);
}

