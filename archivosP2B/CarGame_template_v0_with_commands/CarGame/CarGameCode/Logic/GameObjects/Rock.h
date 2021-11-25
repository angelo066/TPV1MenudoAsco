#pragma once

#include "BadObject.h"

class Rock : public BadObject {

public:
    static const int dimension = 60;
    Rock(Game* game) : BadObject(game) {
        setDimension(dimension, dimension);
    };
    ~Rock() = default;
    void draw() override;
    virtual bool receiveCarCollision(Car* car) override;

};
