#ifndef CARGAME_COMMANDFACTORY_H
#define CARGAME_COMMANDFACTORY_H

#include "Commands/QuitCommand.h"
#include "Commands/MoveCommand.h"
#include "Commands/DebugCommand.h"
#include "Commands/HelpCommand.h"
#include "Commands/AccCommand.h"
#include <vector>

class Game;

class CommandFactory {

    vector<Command *> availableCommands;
    Game *game;
public:
	CommandFactory(Game* g); 

	~CommandFactory();

	Command* getCommand(SDL_Event& event);

	void add(Command* c);
};

#endif //CARGAME_COMMANDFACTORY_H
