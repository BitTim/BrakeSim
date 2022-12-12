#include <iostream>
#include <string>
#include <SDL2/SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const std::string TITLE = "Brake Simulator";

SDL_Window* window = NULL;
SDL_Surface* surface = NULL;

bool init() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not be initialized. SDL Error: %s\n", SDL_GetError());
		return false;
	}

	window = SDL_CreateWindow(TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(window == NULL) {
		printf("Window could not be created. SDL Error: %s\n", SDL_GetError());
		return false;
	}

	surface = SDL_GetWindowSurface(window);
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x11, 0x11, 0x11));
	SDL_UpdateWindowSurface(window);
	SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } } //HACK

	return true;
}

int main(int argc, char* argv[]) {
	if (!init()) return -1;
	
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}