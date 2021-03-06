//
// Created by eys on 20/8/21.
//

#include "Game.h"

//! Car se queda fuera del container para poder recorrer el container
//! Borrando los elementos muertos del mismo
Game::Game(string name, int width, int height, int roadLength) {
	this->name = name;
	this->roadLength = roadLength;
	this->width = width;
	this->height = height;
	doExit = false;
	font = new Font("../Images/Monospace.ttf", 12);
	s = Menu;

	container = new GameObjectContainer();
	info = new Infobar(this);
	debug = false;
	help = false;
}

void Game::startGame() {
	//Coche
	car = new Car(this);
	car->setDimension(CAR_WIDTH, CAR_HEIGHT);
	//Para que la posicion sea el extremo derecho central
	car->setPosition(car->getWidth(), height / 2.0);

	//Meta
	m.t = getTexture(goalTexture);
	m.pos = Point2D<double>(roadLength, 0);
	//Muros
	//setWalls();
	GameObjectGenerator::generateLevel(this, nWalls);
}

bool Game::pointOcuppied(GameObject* o)
{
	return container->hasCollision(o);
}

void Game::clearHelp()
{
	helpInfo.clear();
}

string Game::getStateName()
{
	switch (s)
	{
	case Menu:
		return "Men?";
		break;
	case Playing:
		return "Playing";
		break;
	case Gameover:
		return "GameOver";
		break;
	default:
		break;
	}
}

void Game::waveUsed()
{
	if (coins >= 3) {

		auto gO = container->getGameobjects();

		for (auto g : gO) {
			g->receiveWave();
		}

		coins -= 3;
	}
}

void Game::clearWalls()
{	//Algo hago mal al borrar los muros, y no se que es

}

string Game::getGameName() {
	return name;
}

Game::~Game() {
	cout << "[DEBUG] deleting game" << endl;

	delete car;
	delete textureContainer;
	delete font;
	delete container;
	delete info;
	clearHelp();
}

void Game::update() {
	switch (s)
	{
	case Menu:

		break;
	case Playing:
		car->update();
		container->update();

		//Para que no chequee cuando no haya muros

		//Meta (Para que se mueva)
		m.update(car->getHorizontalV());

		//L?gica del juego	//Para que se vea cruzar la meta
		if (car->getX() > roadLength + CAR_WIDTH) {
			changeState(Gameover);

			razeWon = true;
		}

		if (power == 0) {
			changeState(Gameover);

			razeWon = false;
		}

		razeTime++;

		container->removeDead();
		break;
	case Gameover:
		break;
	default:
		break;
	}
}

void Game::draw() {
	//Se pinta siempre
	info->drawState();
	if (help) {
		info->drawHelp();
	}

	switch (s)
	{
	case Menu:
		drawMenuMessage();
		break;
	case Playing:
		//! Primero el container para que se pinte el coche por encima
		//! Del resto de objetos
		container->draw();
		car->draw();

		//drawInfo();
		info->drawInfo();

		drawGoal();

		if (debug) {
			car->drawDebug();
			container->drawDebug();
		}

		break;
	case Gameover:

		drawGameOverMessage();
		break;
	default:
		break;
	}
}

void Game::drawHelp()
{
	//Le pongo algo de offset para que quede en el medio
	SDL_Rect rect = { getWindowWidth() / 2 - 100,
		getWindowHeight() / 2 - 50, 200,200 };


	renderText("Start by moving the car", rect.x, rect.y);
	rect.y += 10;
	renderText("Move the car by presing ->, up or dow", rect.x, rect.y);
	rect.y += 10;
	renderText("Press j to close help", rect.x, rect.y);
	rect.y += 10;
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
	renderText("Press h for help", rect.x, rect.y);
	rect.y += 10;
}

void Game::drawGameOverMessage()
{
	SDL_Rect rect = { getWindowWidth() / 2 - 100,
	getWindowHeight() / 2 - 50, 200,200 };

	if (razeWon) {
		renderText("Congratulations, you won", rect.x, rect.y);
		rect.y += 10;
		renderText("You needed: " + to_string(razeTime / 30) + " seconds", rect.x, rect.y);
		rect.y += 10;
	}
	else {
		renderText("Te comiste todos los muros de Espa?a", rect.x, rect.y);
		rect.y += 10;
	}

}

void Game::drawGoal()
{
	SDL_Rect dest = { m.pos.getX(), m.pos.getY(), 50, height };

	m.t->render(dest);
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

vector<Collider*> Game::getCollisions(GameObject* o)
{
	return container->getCollisions(o);
}

void Game::resetGame()
{
	power = 3;
	coins = 0;
	razeWon = false;
	car->setPosition(0, height / 2);
	car->resetVelocity();
	razeTime = 0;

	//clearWalls();
	GameObjectGenerator::generateLevel(this, nWalls);

	m.pos.setX(roadLength);
}

bool Game::isRebased(GameObject* gO)
{
	return gO->getX() + gO->getWidth() < 0;
}