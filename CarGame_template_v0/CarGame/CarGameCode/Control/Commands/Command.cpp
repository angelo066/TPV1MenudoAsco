#include "Command.h"
#include "..//..//Logic/Game.h"

//Me he creado el cpp porque en el h no me dejaba llamar metodos
//De game
void Command::bind(Game* game)
{
	this->game = game;
	game->appendHelpInfo(info_string);
}
