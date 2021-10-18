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


using namespace std;

class Game{


private:
	const int nWalls = 20;

    string name;
    bool doExit;
    int roadLength;
    int width, height; //La ventana
    Car *car = nullptr;

    TextureContainer *textureContainer;
    SDL_Renderer* renderer = nullptr;
    Font *font;

	std::vector<Wall*> walls;


	void setWalls();
	bool pointOcuppied(double x, double y);

public:
    const unsigned int CAR_WIDTH = 100;
    const unsigned  int CAR_HEIGHT = 50;

	const unsigned int WALL_WIDTH = 50;
	const unsigned  int WALL_HEIGHT = 50;

    Game(string name, int width, int height, int roadLength);
    ~Game();

    void startGame();
    void update();
    void draw();

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

	void moveCar(bool up);

	void acelerateCar(bool imFast);

	int random(int min,int max);

	bool pointInRect(Point2D<double>p, SDL_Rect r);
};


#endif //CARGAME_GAME_H
