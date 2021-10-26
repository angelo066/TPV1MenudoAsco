//
// Created by eys on 20/8/21.
//

#ifndef CARGAME_GAME_H
#define CARGAME_GAME_H

#include <iostream>
#include <string>
#include <vector>

#include "../View/TextureContainer.h"
#include "../View/Texture.h"
#include "../View/Box.h"
#include "../View/Font.h"

#include "GameObjects/Car.h"
#include "GameObjects/Wall.h"
#include "GameObjects/GameObject.h"
#include "GameObjectContainer.h"
#include "GameObjects/BadObject.h"
#include "GameObjectGenerator.h"

enum States{Menu, Playing, Gameover};


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


private:

	const int nWalls = 20;

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

	std::vector<Wall*> walls;

	GameObjectContainer* container;

	int power = 3;
	float razeTime = 0;

	void setWalls();
	void clearWalls();

public:


    Game(string name, int width, int height, int roadLength);
    ~Game();

    void startGame();
    void update();
    void draw();

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

    void drawInfo();

	void drawGoal();

	void moveCar(bool up);

	void acelerateCar(bool imFast);

	int random(int min,int max);

	bool pointInRect(Point2D<double>p, SDL_Rect r);
	//Estos metodos existen porque se me habia olvidado que SDL los hacia solo
	bool rectInRect(const SDL_Rect& r,const SDL_Rect& r2);

	bool checkCollisions();

	//! Extension del antiguo checkCollisions
	vector<GameObject*> getCollisions(GameObject* o);

	void deleteWall(int indice);

	States getState() { return s; }

	void changeState(States newS) { s = newS; }

	void resetGame();

	bool isRebased(GameObject* gO) { return false; }

	void appendHelpInfo(string info) {};

	double getRoadL() { return roadLength; }

	void addGameObject(GameObject* go) { container->add(go); }

	Car* getCar() { return car; }

	bool pointOcuppied(GameObject* o);
};

#endif //CARGAME_GAME_H