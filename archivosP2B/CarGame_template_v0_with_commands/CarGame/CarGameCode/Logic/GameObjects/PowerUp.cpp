#include "PowerUp.h"

#include "../Game.h"

void PowerUp::draw() {
    drawTexture(game->getTexture(powerUpTexture));
}

bool PowerUp::receiveCarCollision(Car* car) {
    // TODO
    return false;
}