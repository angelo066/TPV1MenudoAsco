#include "Bullet.h"
#include "..//Game.h"

Bullet::Bullet(Game* gam, double x, 
	double y, int w_, int h_) : GoodObject(gam)
{
	initPos = game->getCar()->getX();

	setPosition(x, y);
	setDimension(w_, h_);

	onEnter();
}

Bullet::~Bullet()
{

}

void Bullet::collidedWithSomthing()
{
	alive = false;
}

void Bullet::update()
{
	setPosition(getX() + bulletSpeed,
		getY());

	//Comprobamos la colisiones
	vector<Collider*> gOs = game->getCollisions(this);

	for (auto g : gOs) {
		g->receiveBulletCollision(this);
	}

	//Si se sale de rango la borro
	if (getX() - initPos >= 700) 
		alive = false;
}

void Bullet::draw()
{
	drawTexture(game->getTexture(bulletTexture));
}

void Bullet::drawDebug()
{
	Box(getCollider(), BLACK).render(game->getRenderer());
}
