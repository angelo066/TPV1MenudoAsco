//
// Created by eys on 20/8/21.
//

#include "ViewController.h"


ViewController::ViewController(Game* _game) {
	game = _game;
	cout << "[DEBUG] frame duration: " << frameDuration() << " ms" << endl;
	initSDL();

	game->setRenderer(renderer);
	game->loadTextures();

	commandFactory = new CommandFactory(game);
	commandFactory->add(new QuitCommand());
	commandFactory->add(new AccCommand());
	commandFactory->add(new MoveCommand());
	commandFactory->add(new DebugCommand());
}

void ViewController::run() {
	uint32_t startTime = 0;
	uint32_t frameTime;
	game->startGame();

	while (!game->doQuit()) {
		frameTime = SDL_GetTicks() - startTime;
		handleEvents();
		if (frameTime >= frameDuration()) {
			clearBackground();
			game->update();
			game->draw();
			SDL_RenderPresent(renderer);
			startTime = SDL_GetTicks();
		}
		else {
			SDL_Delay(frameDuration() - frameTime);
		}
	}
}

void ViewController::clearBackground() {
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void ViewController::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		Command* command = commandFactory->getCommand(event);
		if (command != nullptr) {
			command->execute();
			break;	//? por que hay aqui un break
		}


		//      if( event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
  //          game->setUserExit();

		//switch (game->getState())
		//{
		//case Menu:
		//	if (event.key.keysym.sym == SDLK_SPACE) {
		//		game->changeState(Playing);
		//	}

		//	break;
		//case Playing:
		//	if (event.key.keysym.sym == SDLK_UP) {
		//		game->moveCar(true);
		//	}
		//	else if (event.key.keysym.sym == SDLK_DOWN) {
		//		game->moveCar(false);
		//	}
		//	else if (event.key.keysym.sym == SDLK_RIGHT) {
		//		game->acelerateCar(true);
		//	}
		//	else if (event.key.keysym.sym == SDLK_LEFT) {
		//		game->acelerateCar(false);
		//	}
		//	break;
		//case Gameover:
		//	if (event.key.keysym.sym == SDLK_SPACE) {
		//		game->changeState(Playing);

		//		game->resetGame();
		//	}

		//	break;
		//default:
		//	break;
		//}

	}
}

uint32_t ViewController::frameDuration() {
	return 1000 / FRAME_RATE;
}

void ViewController::initSDL() {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow(game->getGameName().c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		game->getWindowWidth(),
		game->getWindowHeight(),
		SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr)
		throw string("Error creating SDL window or renderer");

	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, &screenSurface->clip_rect, 0xFF);
	SDL_UpdateWindowSurface(window);
}

ViewController::~ViewController() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
