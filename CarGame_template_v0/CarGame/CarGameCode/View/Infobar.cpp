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

	switch (game->s)
	{
	case Menu:
		drawMenuHelp(rect);
		break;

	case Playing:
		drawPlayingHelp(rect);
		break;

	case Gameover:
		game->renderText("Move To Play Again", rect.x, rect.y);
		break;
	default:
		break;
	}


}

void Infobar::drawPlayingHelp(SDL_Rect& rect)
{
	game->renderText("[UP/DOWn] to Move", rect.x, rect.y);
	rect.y += 10;
	game->renderText("[RIGHT/LEFT] to speed up", rect.x, rect.y);
	rect.y += 10;
	game->renderText("[s] to shoot", rect.x, rect.y);
	rect.y += 10;
	game->renderText("[q] to debug", rect.x, rect.y);
	rect.y += 10;
	game->renderText("[h] to toggle help", rect.x, rect.y);
	rect.y += 10;
	game->renderText("[] space to skip", rect.x, rect.y);
	rect.y += 10;
	game->renderText("[ESC] to quit", rect.x, rect.y);
	rect.y += 10;
}

void Infobar::drawMenuHelp(SDL_Rect& rect)
{
	game->renderText("[h] to toggle help", rect.x, rect.y);
	rect.y += 10;
	game->renderText("[] space to skip", rect.x, rect.y);
	rect.y += 10;
	game->renderText("[ESC] to quit", rect.x, rect.y);
	rect.y += 10;
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
