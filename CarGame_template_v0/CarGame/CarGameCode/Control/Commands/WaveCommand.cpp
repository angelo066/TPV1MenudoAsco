#include "WaveCommand.h"
#include "..//..//Logic/Game.h"


bool WaveCommand::parse(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN) {

		if (event.key.keysym.sym == SDLK_w) {
			return true;
		}
	}

	return false;
}

void WaveCommand::execute()
{
	game->waveUsed();
}
