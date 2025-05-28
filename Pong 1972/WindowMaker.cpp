#include <SDL3/SDL.h>
#include <iostream>
#include "WindowMaker.h"


WindowMaker::WindowMaker(const char* title ,int width, int height) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_CreateWindowAndRenderer(title, width, height, SDL_WINDOW_OPENGL, &window, &renderer);


}

void WindowMaker::clearWindow() {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void WindowMaker::destroyWindow() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

}

void WindowMaker::render(Player player) {

	SDL_SetRenderDrawColor(renderer, 210, 235, 255,255);
	SDL_RenderFillRect(renderer, &(player.getRect()));
	

}

void WindowMaker::present() {
	SDL_RenderPresent(renderer);

}