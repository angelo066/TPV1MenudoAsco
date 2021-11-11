#include "DebugCommand.h"
#include "..//..//Logic/Game.h"

bool DebugCommand::parse(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_q) {
			debug = true;
			return true;
		}

		if (event.key.keysym.sym == SDLK_e) {
			debug = false;
			return true;
		}

	}

	return false;
}

void DebugCommand::execute()
{
	if (debug)game->changeDebug(true);
	else game->changeDebug(false);
}
