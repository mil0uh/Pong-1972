#pragma once
#include <SDL3/SDL.h>
#include <iostream>

class Player {
private:
	SDL_FRect src;
	int x_pos;
	int y_pos;
	const char* playerName;
public:
	Player(int x_pos, int y_pos, const char* playerName);
	SDL_FRect& getRect();

};