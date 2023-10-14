#pragma once

#include "game.h"

Game *game = nullptr;

int main( int argc, char* args[] ) {

	game = new Game();

	int windowSize = 900;

	game->init("Sudoku", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSize, windowSize, false);

	while(game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	return 0;
}