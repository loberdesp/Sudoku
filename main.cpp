#include "headers.h"

Game *game = nullptr;

int main( int argc, char* args[] )
{
	game = new Game();

	game->init("Sudoku", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_SIZE, WINDOW_SIZE, false);

	while(game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	return 0;
}