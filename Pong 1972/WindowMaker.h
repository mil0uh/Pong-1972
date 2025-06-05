#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include "Entity.h"

class WindowMaker {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	
public:
	WindowMaker(const char* title, int width, int height);
	
	void destroyWindow();
	void renderPlayers(Entity& entity);
	void render(Entity& entity);
	SDL_Texture* loadTexture(const char* filePath);
	void present();
	void clearWindow();
};