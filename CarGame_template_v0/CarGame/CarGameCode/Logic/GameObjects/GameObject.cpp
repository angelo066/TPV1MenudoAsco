#include "GameObject.h"
#include "..//Game.h"

void GameObject::setPosition(double x, double y)
{
	pos = Point2D<double>(x, y);
}

void GameObject::setDimension(double width, double height)
{
	w = width;
	h = height;
}
