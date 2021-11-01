//
// Created by eys on 21/8/21.
//

#include "Car.h" //El truco del almendruco
#include "../Game.h"

Car::Car(Game *game) : GameObject(game){
    this->game = game;
    texture = nullptr;

	//todos a false
	acelerating = false;
	up = down = false;
}

void Car::update() {
	movement();

	vector<Collider*> gOs = game->getCollisions(this);

	for (auto g : gOs) {
		g->receiveCarCollision(this);
	}
}

void Car::movement()
{
	//Luego con los estados hago que al principio no se mueva
	if (!acelerating)HSPEED = HSPEED * DECELERATION;
	else if (acelerating && HSPEED * ACCELERATION <= MAX_SPEED) HSPEED = HSPEED * ACCELERATION;

	setPosition(getX() + HSPEED, getY());

	float y = getY();
	if (up && y - getHeight() / 2 - 5 >= 0)setPosition(getX(), getY() - VSPEED);
	else if (down && y + getHeight() / 2 <= game->getWindowHeight())setPosition(getX(), getY() + VSPEED);
}

Car::~Car(){};

void Car::draw() {
    drawTexture(game->getTexture(carTexture));
}

void Car::drawTexture(Texture *texture) {
    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x, c.y, c.w, c.h};
    texture->render(textureBox);
}

SDL_Rect Car::getCollider(){
	//Porque mide la posicion como el extremo derecho central
	//? No puedo poner que la x sea siempre 0 y que la y sea 
	//? su posicion en y
    return { 0,
             int(getY() - getHeight() / 2), //Por que /2? 
             getWidth(),				//Porque pos.y está a la mitad
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

void Car::stop()
{
	HSPEED = 0;
	up = false;
	down = false;
}
