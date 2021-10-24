#ifndef CARGAME_COMMAND_H
#define CARGAME_COMMAND_H

// TODO add includes
#include <string>
#include <SDL.h>

class Game;

using namespace std;

class Command {
protected:
    string info_string;
    Game *game;
public:

    Command(){};
    virtual ~Command()=default;
    virtual bool parse(SDL_Event &event)=0;
    virtual void execute()=0;
	void bind(Game* game);
};


#endif //CARGAME_COMMAND_H
