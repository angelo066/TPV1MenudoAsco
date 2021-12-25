#ifndef CARGAME_GAMEOBJECTGENERATOR_H
#define CARGAME_GAMEOBJECTGENERATOR_H

#include "GameObjects/Wall.h"
#include "GameObjects/hearth.h"
#include "GameObjects/Coin.h"
#include "GameObjects/Turbo.h"
#include "GameObjects/SuperRock.h"
#include "GameObjects/Oil.h"
#include "GameObjects/Truck.h"
#include "..//..//checkML.h"
//He metido aqui class y el include en el cpp
class Game;
using Rock = Wall;

class GameObjectGenerator {

    Point2D<int> static generateRandomPosition(Game *game, GameObject *o);
    void static addInRandomPosition(Game *game, GameObject *o);

	const static int obtaclesBegin = 300;
	const static int nCoins = 1;
	const static int nHearths = 1;
	const static int nTurbos = 1;
	const static int nSuperRocks = 1;
	const static int nOils = 1;
	const static int nTrucks = 20;
public:
    static void generateLevel(Game *game, int N_ROCKS = 0){
		for (int i = 0; i < N_ROCKS; i++) {
           addInRandomPosition(game, new Rock(game));
		}

		//Crear power ups alatorios
		for (int i = 0; i < nHearths; i++) {
			addInRandomPosition(game, new Hearth(game));

		}

		for (int i = 0; i < nCoins; i++) {
			addInRandomPosition(game, new Coin(game));
		}

		for (int i = 0; i < nTurbos; i++) {
			addInRandomPosition(game, new Turbo(game));
		}

		for (int i = 0; i < nSuperRocks; i++) {
			addInRandomPosition(game, new SuperRock(game));
		}

		for (int i = 0; i < nOils; i++) {
			addInRandomPosition(game, new Oil(game));
		}

		for (int i = 0; i < nTrucks; i++) {
			addInRandomPosition(game, new Truck(game));
		}
    }   
};


#endif //CARGAME_GAMEOBJECTGENERATOR_H
