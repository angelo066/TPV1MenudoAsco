#include "Rock.h"
#include "../Game.h"


void Rock::draw() {
    drawTexture(game->getTexture(rockTexture));
}

bool Rock::receiveCarCollision(Car* car) {
   // TODO
    return false;
}

