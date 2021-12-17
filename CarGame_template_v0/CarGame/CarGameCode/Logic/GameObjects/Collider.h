#ifndef CARGAME_COLLIDER_H
#define CARGAME_COLLIDER_H

class Car;
class Bullet;

class Collider {
protected:
	const int waveEffect = 150;


public:
    virtual bool receiveCarCollision(Car *car){
        return false;
    };

	virtual bool receiveBulletCollision(Bullet* bullet) {
		return false;
	};

	virtual void receiveWave() {

	};
};

#endif //CARGAME_COLLIDER_H