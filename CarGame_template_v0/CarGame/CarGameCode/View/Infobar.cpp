#include "Infobar.h"

#include "..//Logic/Game.h"


void Infobar::drawInfo()
{
	Font* f = game->font;

	int x = f->getSize() / 2;
	int y = f->getSize() / 2;

	SDL_Rect rect = { 0, 0, game->getWindowWidth(),
				 int(f->getSize() * 1.8) };
	Box(rect, BLACK).render(game->renderer);

	Car* c = game->car;
	string s = "Pos: " + to_string(int(c->getX())) + "   "
		+ to_string(int(c->getY())) + "   " + "Distance left:" +
		to_string((int)game->roadLength - (int)c->getX()) + "   "
		+ "Speed:" + to_string((int)c->getHorizontalV()) + "   " +"Coins:" +
		to_string(GoodObject::instances)+"   "+
		"Power: " + to_string(game->power) + "   " + "Objs: " + "["+
		to_string(BadObject::instances)+","+ to_string(GoodObject::instances) 
		+"]"+ " " + "Time:" +
		to_string(game->razeTime / 30);	//30 porque son los FPS


	game->renderText(s, x, y);
}

void Infobar::drawHelp()
{
	string s;

	Font* f = game->font;

	int x = f->getSize() / 2;
	int y = f->getSize() / 2;

	SDL_Rect rect = { 0, 20, game->getWindowWidth(),
				 int(f->getSize() * 1.8) };


	vector<string> h = game->helpInfo;

	for (int i = 0; i < h.size(); i++) {
		game->renderText(h[i], rect.x, rect.y);
		rect.y += 10;
	}

}

void Infobar::drawState()
{
	Font* f = game->font;

	int x = f->getSize() / 2;
	int y = f->getSize() / 2;

	SDL_Rect rect = { 0, game->getWindowHeight()-20, game->getWindowWidth(),
				 int(f->getSize() * 1.8) };
	Box(rect, BLACK).render(game->renderer);

	string s = game->getStateName();

	game->renderText(s, rect.x, rect.y);
}
