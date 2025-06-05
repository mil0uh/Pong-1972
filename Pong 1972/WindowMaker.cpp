#include <SDL3/SDL.h>
#include <iostream>
#include "WindowMaker.h"
#include "Entity.h"


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

void WindowMaker::renderPlayers(Entity& entity) {

	SDL_SetRenderDrawColor(renderer, 210, 235, 255,255);
	SDL_RenderFillRect(renderer, &entity.getCurrentFrame());
	

}


void WindowMaker::render(Entity& entity) {

	SDL_FRect src;
	src.x = entity.getCurrentFrame().x;
	src.y = entity.getCurrentFrame().y;
	src.w = entity.getCurrentFrame().w;
	src.h = entity.getCurrentFrame().h;

	SDL_FRect dst;

	dst.x = entity.getX();
	dst.y = entity.getY();
	dst.w = entity.getCurrentFrame().w;
	dst.h = entity.getCurrentFrame().h;

	SDL_RenderTexture(renderer, entity.getTexture(), &src, &dst);

}

void WindowMaker::present() {
	SDL_RenderPresent(renderer);

}

SDL_Texture* WindowMaker::loadTexture(const char* filePath) {
	SDL_Texture* texture = NULL;

	texture = IMG_LoadTexture(renderer, filePath);

	if (texture == nullptr) {
		std::cerr << "Error: Could not load texture - Please Check File Path" << std::endl;
	}

	return texture;
}