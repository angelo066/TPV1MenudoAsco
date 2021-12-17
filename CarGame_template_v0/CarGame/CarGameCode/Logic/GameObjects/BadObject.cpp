#include "BadObject.h"

// TODO: add includes
#include "..//Game.h"

void  BadObject::onEnter(){
    instances += 1;
};

void  BadObject::onDelete(){
    instances -= 1;
};

void BadObject::reset() {
	instances = 0;
};

void BadObject::receiveWave()
{
	setPosition(getX() + waveEffect, getY());
}

bool BadObject::toDelete() {
    return !alive || game->isRebased(this);
}

int BadObject::instances = 0;