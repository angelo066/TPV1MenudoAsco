//
// Created by eys on 21/8/21.
//

#include "Car.h"
#include "../Game.h"

Car::Car(Game *game){
    this->game = game;
    texture = nullptr;

	//todos a false
	acelerating = false;
	up = down = false;
}

void Car::setDimension(int width, int height){
    w = width;
    h = height;
};

void  Car::setPosition(double x, double y){
    pos = Point2D<double>(x, y);
};

void Car::update() {
	//Luego con los estados hago que al principio no se mueva
	if(!acelerating)HSPEED = HSPEED * DECELERATION;
	else if(acelerating && HSPEED * ACCELERATION <= MAX_SPEED) HSPEED = HSPEED * ACCELERATION;

    pos = Point2D<double>(getX() + HSPEED, getY());

	float y = getY();
    if(up && y - h / 2 - 5 >= 0)pos = Point2D<double>(getX(), getY() - VSPEED);
	else if(down && y + h / 2 <= game->getWindowHeight())pos = Point2D<double>(getX(), getY() + VSPEED);
}

Car::~Car(){};

void Car::draw() {
    drawTexture(game->getTexture(carTexture));
}


void Car::drawTexture(Texture *texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h};
    texture->render(textureBox);
}


SDL_Rect Car::getCollider(){
    return { int(getX() - getWidth()),
             int(getY() - getHeight()/2),
             getWidth(),
             getHeight()};
}

void Car::acelerate(bool imFast)
{
	//Un montond e ifs, complicado
	if (imFast && HSPEED == 0) HSPEED = 1;

	if (imFast && HSPEED * ACCELERATION <= MAX_SPEED) {
		acelerating = true;
	}
	
	if (!imFast) {
		acelerating = false;
	}

}

void Car::goinUp(bool upper)
{
	if (upper) {
		up = true;
		down = false;
	}
	else {
		up = false;
		down = true;
	}
}
