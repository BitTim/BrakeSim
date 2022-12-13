#include <stdio.h>
#include <SDL2/SDL.h>

#include "../lib/managers/initializers.hh"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const char* TITLE = "Brake Simulator";

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event;

bool quit = false;

bool init() {
	if(!Init::SDL(TITLE)) return false;
	return true;
}

void end() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void handleEvent() {
	SDL_PollEvent(&event);
	if(event.type == SDL_QUIT) quit = true;
}

void update() {
	// Insert Updating here
}

void render() {
	SDL_SetRenderDrawColor(renderer, 0x11, 0x11, 0x11, 0xFF);
	SDL_RenderClear(renderer);

	// Insert rendering here

	SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
	if (!init()) return -1;
	
	while(!quit) {
		handleEvent();
		update();
		render();
	}

	end();
	return 0;
}