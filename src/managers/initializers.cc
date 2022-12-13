#include <stdio.h>
#include "../../lib/managers/initializers.hh"

bool Init::SDL(const char* title) {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not be initialized. SDL Error: %s\n", SDL_GetError());
		return false;
	}

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(window == NULL) {
		printf("Window could not be created. SDL Error: %s\n", SDL_GetError());
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0x11, 0x11, 0x11, 0xFF);
  	SDL_RenderClear(renderer);
  	SDL_RenderPresent(renderer);

	return true;
}