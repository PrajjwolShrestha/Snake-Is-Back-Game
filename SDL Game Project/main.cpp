#include "Sdl_includes.h" //header file that contains SDL files (SDL_image, SDL_ttf, SDL.h)
#include "Game.h"
#include "Utils.h"


Snake::Game* game = 0;

//for SDL to work, need old 'main' signature, not void main()

int main(int argc, char* argv[]) {
	game = new Snake::Game();
	
	game->init();

	//while the game is running , we handle different events, update and render it t screen
	while (game->isRunning()) {
		game->handleEvents();
		game->update();
		game->render();
		SDL_Delay(10); //SDL delay for 10 ms
	}

	
	game->clean(); //clean up the memory

	return 0;
}
