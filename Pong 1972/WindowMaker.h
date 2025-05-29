#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include "Player.h"

class WindowMaker {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	
public:
	WindowMaker(const char* title, int width, int height);
	
	void destroyWindow();
	void render(Player player);
	void render(Player player, int r, int g, int b, int a);
	void present();
	void clearWindow();
};