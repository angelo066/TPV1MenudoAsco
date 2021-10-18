//
// Created by eys on 20/8/21.
//

#include "Game.h"


Game::Game(string name, int width, int height, int roadLength) {
    this->name = name;
    this->roadLength = roadLength;
    this->width = width;
    this->height = height;
    doExit = false;
    font = new Font("../Images/Monospace.ttf", 12);
}

void Game::startGame() {
    car = new Car(this);
    car->setDimension(CAR_WIDTH, CAR_HEIGHT);
    car->setPosition(car->getWidth(), height/ 2.0);

	setWalls();
}

void Game::setWalls()
{
	for (int i = 0; i < nWalls; i++) {
		double x = random(300, roadLength);
		double y = random(0, height);

		if (!pointOcuppied(x, y)) {
			Wall* w = new Wall(this, car, x, y, WALL_WIDTH, WALL_HEIGHT);
			walls.push_back(w);
		}
	}
}

bool Game::pointOcuppied(double x, double y)
{
	//Caso en el que no tengo muros
	if (walls.empty()) return false;

	bool occuppied = false;
	int i = 0;

	//Comprobamos posiciones en todos los walls
	while (i < walls.size() &&
		!pointInRect(Point2D<double>(x,y), 
			walls[i]->getDestRect())) i++;

	if (i < walls.size())occuppied = true;
	return occuppied;
}

string Game::getGameName() {
    return name;
}

Game::~Game() {
    cout << "[DEBUG] deleting game" << endl;
}

void Game::update(){
    car->update();

	for (auto w : walls) w->update();
}

void Game::draw(){
    car->draw();
    drawInfo();

	//Es viable usar auto o vivimos en el siglo 16?
	for (auto w : walls) {
		w->draw();
	}
}

void Game::drawInfo() {
    int x = font->getSize() / 2;
    int y = font->getSize() / 2;

    SDL_Rect rect = {0, 0, getWindowWidth(),
                     int(font->getSize() * 1.8)};
    Box(rect, BLACK).render(renderer);

    string s = "Pos: " + to_string(int(car->getX())) + " "
               + to_string(int(car->getY()));
    renderText(s, x, y);
}

void Game::setUserExit() {
    doExit = true;
}

bool Game::isUserExit() {
    return doExit;
}

int Game::getWindowWidth(){
    return width;
}

int Game::getWindowHeight() {
    return height;
}

SDL_Renderer *Game::getRenderer() {
    return renderer;
}

void Game::setRenderer(SDL_Renderer *_renderer) {
    renderer = _renderer;
}

void Game::loadTextures() {
    if(renderer == nullptr)
        throw string("Renderer is null");

    textureContainer = new TextureContainer(renderer);
}

void Game::renderText(string text, int x, int y, SDL_Color color){
    font->render(renderer, text.c_str(), x, y, color);
}

bool Game::doQuit() {
    return isUserExit();
}

Texture *Game::getTexture(TextureName name) {
    return textureContainer->getTexture(name);
}
//Returneas la esquina superior iz. coche
Point2D<int> Game::getOrigin() {
    return {int(-(car->getX() - car->getWidth())), 0};
}

void Game::moveCar(bool up)
{
	//Si va hacia arriba lo restamos, si va hacia abajo sumamos
	float y = car->getY();
	if (up && y - CAR_HEIGHT/2 - 5 >= 0) {
		car->goinUp(true);
	}

	if(!up && y + CAR_HEIGHT/2 <= height){
		car->goinUp(false);
	}
}

void Game::acelerateCar(bool imFast)
{
	car->acelerate(imFast);
}

int Game::random(int min,int max)
{
	return rand() % max + min;
}

bool Game::pointInRect(Point2D<double> p, SDL_Rect r)
{
	double extremoD = p.getX() + r.x + r.w;
	double extremoS = p.getY() + r.y + r.h;

	return (p.getX() > r.x && p.getX() < extremoD
		&& p.getY() > r.y && p.getY() < extremoS);
}
