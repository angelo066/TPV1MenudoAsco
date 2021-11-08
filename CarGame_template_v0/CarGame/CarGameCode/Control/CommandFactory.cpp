#include "CommandFactory.h"

#include "..//Logic/Game.h"

CommandFactory::CommandFactory(Game* g)
{
	game = g;
	game->clearHelp();
}

CommandFactory::~CommandFactory()
{
	for (auto c : availableCommands)
		delete c;
}

Command* CommandFactory::getCommand(SDL_Event& event)
{
	for (auto c : availableCommands) {
		//! He tenido que modificar el c�digo
		if (event.type == SDL_KEYDOWN && c->parse(event)) return c;
	}
	return nullptr;
}

void CommandFactory::add(Command* c)
{
	c->bind(game);
	availableCommands.push_back(c);
}
