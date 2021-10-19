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
	s = Menu;
}

void Game::startGame() {
    car = new Car(this);
    car->setDimension(CAR_WIDTH, CAR_HEIGHT);
	//Para que la posicion sea el extremo derecho central
    car->setPosition(car->getWidth(), height/ 2.0);

	setWalls();
}

void Game::setWalls()
{
	for (int i = 0; i < nWalls; i++) {
		double x = random(300, roadLength);
		double y = random(0, height);

		Wall* w = new Wall(this, car, x, y, WALL_WIDTH, WALL_HEIGHT);
		if (!pointOcuppied(w->getRect())) {
			walls.push_back(w);
		}
	}
}

bool Game::pointOcuppied(SDL_Rect newR)
{
	//Caso en el que no tengo muros
	if (walls.empty()) return false;

	int i = 0;
	bool occuppied = rectInRect(newR, walls[i]->getRect());

	//Comprobamos posiciones en todos los walls
	while (i < walls.size() && !occuppied) {
		occuppied = rectInRect(newR, walls[i]->getRect());

		i++;
	}

	return occuppied;
}

string Game::getGameName() {
    return name;
}

Game::~Game() {
    cout << "[DEBUG] deleting game" << endl;
}

void Game::update(){
	switch (s)
	{
	case Menu:

		break;
	case Playing:
		car->update();

		for (auto w : walls) w->update();

		//Para que no chequee cuando no haya muros
		if (!walls.empty() && checkCollisions()) {
			power--;
			car->stop();
		}

		break;
	case Gameover:
		break;
	default:
		break;
	}
}

void Game::draw(){
	switch (s)
	{
	case Menu:
		drawMenuMessage();
		break;
	case Playing:

		car->draw();
		drawInfo();

		for (auto w : walls) {
			w->draw();
		}

		break;
	case Gameover:
		break;
	default:
		break;
	}
}

void Game::drawMenuMessage()
{
	//Le pongo algo de offset para que quede en el medio
	SDL_Rect rect = { getWindowWidth() / 2 - 100,
		getWindowHeight() / 2 - 50, 200,200 };


	renderText("Welcome To Super Cars", rect.x, rect.y);
	rect.y += 10;
	renderText("Level: 0", rect.x, rect.y);
	rect.y += 10;
	renderText("Press space to start", rect.x, rect.y);
	rect.y += 10;
}

void Game::drawInfo() {
int x = font->getSize() / 2;
int y = font->getSize() / 2;

SDL_Rect rect = { 0, 0, getWindowWidth(),
				 int(font->getSize() * 1.8) };
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

int Game::getWindowWidth() {
	return width;
}

int Game::getWindowHeight() {
	return height;
}

SDL_Renderer* Game::getRenderer() {
	return renderer;
}

void Game::setRenderer(SDL_Renderer* _renderer) {
	renderer = _renderer;
}

void Game::loadTextures() {
	if (renderer == nullptr)
		throw string("Renderer is null");

	textureContainer = new TextureContainer(renderer);
}

void Game::renderText(string text, int x, int y, SDL_Color color) {
	font->render(renderer, text.c_str(), x, y, color);
}

bool Game::doQuit() {
	return isUserExit();
}

Texture* Game::getTexture(TextureName name) {
	return textureContainer->getTexture(name);
}
//Returneas la esquina superior iz. coche
Point2D<int> Game::getOrigin() {
	return { int(-(car->getX() - car->getWidth())), 0 };
}

void Game::moveCar(bool up)
{
	//Si va hacia arriba lo restamos, si va hacia abajo sumamos
	float y = car->getY();
	if (up && y - CAR_HEIGHT / 2 - 5 >= 0) {
		car->goinUp(true);
	}

	if (!up && y + CAR_HEIGHT / 2 <= height) {
		car->goinUp(false);
	}
}

void Game::acelerateCar(bool imFast)
{
	car->acelerate(imFast);
}

int Game::random(int min, int max)
{
	return rand() % max + min;
}

bool Game::pointInRect(Point2D<double> p, SDL_Rect r)
{
	double extremoD = r.x + r.w;
	double extremoS = r.y + r.h;

	return (p.getX() > r.x && p.getX() < extremoD
		&& p.getY() > r.y && p.getY() < extremoS);
}

bool Game::rectInRect(const SDL_Rect& r, const SDL_Rect& r2)
{
	//Comprobar every esquina
	bool insideLUc = pointInRect(Point2D<double>(r.x,r.y), r2);
	bool insideRUc = pointInRect(Point2D<double>(r.x + r.w, r.y), r2);
	bool insideLDc = pointInRect(Point2D<double>(r.x + r.w, r.y + r.h), r2);
	bool insideRDc = pointInRect(Point2D<double>(r.x, r.y + r.h), r2);

	return insideLDc || insideLUc || insideRDc || insideRUc;
}

bool Game::checkCollisions()
{
	int i = 0;

	SDL_Rect carR = car->getCollider();
	//Le sumo el origen para que las colisiones se hagan como
	//si estuviera a 0, que es donde esta en SDL
	int dX = getOrigin().getX();
	int dY = getOrigin().getY();
	carR.x += dX;
	carR.y += dY;


	bool collision = pointInRect(walls[i]->getPos(), carR);

	//-1 porque comprobamos el primero arriba
	while (i < walls.size() - 1 && !collision)
	{
		i++;
		SDL_Rect wallR = walls[i]->getRect();
		collision = rectInRect(wallR, carR);

	}

	if (collision)
		deleteWall(i);

	return collision;
}

void Game::deleteWall(int indice)
{
	delete walls[indice];
	walls.erase(walls.begin() + indice);
}
