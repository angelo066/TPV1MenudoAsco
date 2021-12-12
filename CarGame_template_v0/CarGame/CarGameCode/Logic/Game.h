//
// Created by eys on 20/8/21.
//

#ifndef CARGAME_GAME_H
#define CARGAME_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <string>

#include "../View/TextureContainer.h"
#include "../View/Texture.h"
#include "../View/Box.h"
#include "../View/Font.h"

#include "GameObjects/Car.h"
#include "GameObjects/GameObject.h"
#include "GameObjectContainer.h"
#include "GameObjects/BadObject.h"
#include "GameObjectGenerator.h"

#include "..//View/Infobar.h"
#include "..//..//checkML.h"

enum States { Menu, Playing, Gameover };

using namespace std;
	//Struct de la meta para que sea más fácil construirla
struct Meta {
	Point2D<double> pos;

	Texture* t;

	void update(double carVel) {
		pos.setX(pos.getX() - carVel);
	}
};

class Game{

	friend class Infobar;
private:

	const int nWalls = 10;

	//! Cambiar a archivos de car y wall
    const unsigned int CAR_WIDTH = 100;
    const unsigned  int CAR_HEIGHT = 50;

	const unsigned int WALL_WIDTH = 50;
	const unsigned  int WALL_HEIGHT = 50;

    string name;
	bool doExit, razeWon;
    int roadLength;
    int width, height; //La ventana
    Car *car = nullptr;

	States s;
	Meta m;

    TextureContainer *textureContainer;
    SDL_Renderer* renderer = nullptr;
    Font *font;

	GameObjectContainer* container;
	Infobar* info;

	int power = 3;
	int coins = 3;
	float razeTime = 0;

	void clearWalls();

	bool debug, help;

	vector<string> helpInfo;
public:


    Game(string name, int width, int height, int roadLength);
    ~Game();

    void startGame();
    void update();
    void draw();

	void drawHelp();

	void drawMenuMessage();
	void drawGameOverMessage();

    void setUserExit();
    bool isUserExit();
    bool doQuit();

    int getWindowWidth();
    int getWindowHeight();

    Point2D<int> getOrigin();

    string getGameName();

    void setRenderer(SDL_Renderer *renderer);
    void loadTextures();
    Texture *getTexture(TextureName name);
    SDL_Renderer *getRenderer();
    void renderText(string text, int x, int y, SDL_Color color={0,0,0});

	void drawGoal();

	void moveCar(bool up);

	void acelerateCar(bool imFast);

	int random(int min,int max);

	//! Extension del antiguo checkCollisions
	vector<Collider*> getCollisions(GameObject* o);

	States getState() { return s; }

	void changeState(States newS) { s = newS; }

	void resetGame();

	bool isRebased(GameObject* gO);

	void appendHelpInfo(string info) { helpInfo.push_back(info); }

	double getRoadL() { return roadLength; }

	void addGameObject(GameObject* go) { container->add(go); }

	Car* getCar() { return car; }

	bool pointOcuppied(GameObject* o);

	void receiveDmg(int d) { power -= d; }

	void heal(int h) { power += h; }

	void clearHelp();

	void changeDebug(bool d) { debug = d; }

	bool getDebug() { return debug; }

	bool getHelp() { return help; }

	void setHelp(bool h) { help = h; }

	Font* getFont() { return font; }

	int getPower() { return power; }

	float getRazeTime() { return razeTime; }

	string getStateName();

	void stopCar() { car->stop(); }

	void addCoin() { coins++; }

	int getCoins() { return coins; }
	
	void useCoin() { coins--; }
};

#endif //CARGAME_GAME_