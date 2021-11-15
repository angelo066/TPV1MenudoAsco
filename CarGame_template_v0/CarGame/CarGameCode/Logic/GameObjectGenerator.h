#ifndef CARGAME_GAMEOBJECTGENERATOR_H
#define CARGAME_GAMEOBJECTGENERATOR_H

#include "GameObjects/Wall.h"
#include "GameObjects/hearth.h"
#include "..//..//checkML.h"
//He metido aqui class y el include en el cpp
class Game;
using Rock = Wall;

class GameObjectGenerator {
    Point2D<int> static generateRandomPosition(Game *game, GameObject *o);
    void static addInRandomPosition(Game *game, GameObject *o);

	void static randomPowerUp(Game* g);

public:
    static void generateLevel(Game *game, int N_ROCKS = 0){
		for (int i = 0; i < N_ROCKS; i++) {
           addInRandomPosition(game, new Rock(game));
			//Crear power ups alatorios
			randomPowerUp(game);
		}
    }   
};


#endif //CARGAME_GAMEOBJECTGENERATOR_H
