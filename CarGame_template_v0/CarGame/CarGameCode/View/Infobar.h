#ifndef CARGAME_INFOBAR_H
#define CARGAME_INFOBAR_H
#include "..//Logic/GameObjects/Car.h"
#include "..//..//checkML.h"
class Game;

class Infobar {
    Game *game;
public:
    Infobar(Game *game):game(game){}

    void drawInfo();
    void drawHelp();
    void drawState();
};


#endif //CARGAME_INFOBAR_H
