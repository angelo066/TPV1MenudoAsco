#pragma once
class Game;
#include "GoodObject.h"

class PowerUp : public GoodObject {
public:
    static const int dimension = 40;

    PowerUp(Game* game) : GoodObject(game) {
        setDimension(dimension, dimension);
    };
    ~PowerUp() override = default;

    void draw() override;
    bool receiveCarCollision(Car* car) override;
};