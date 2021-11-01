#include "GameObject.h"
#include "..//Game.h"

void GameObject::drawTexture(Texture* texture)
{
	SDL_Rect c = getCollider();
	SDL_Rect textureBox = { c.x, c.y, c.w, c.h };
	texture->render(textureBox);
}

void GameObject::setPosition(double x, double y)
{
	pos = Point2D<double>(x, y);
}

void GameObject::setDimension(double width, double height)
{
	w = width;
	h = height;
}

SDL_Rect GameObject::getCenter()
{
	return { (int)pos.getX() + w / 2, (int)pos.getY() + h / 2, 0,0 };
};

