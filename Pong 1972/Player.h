#pragma once
#include <SDL3/SDL.h>
#include <iostream>

class Player {
private:
	SDL_FRect src;
	float x_pos;
	float y_pos;
	Uint64 last = 0;
	const char* playerName;
public:
	Player(float x_pos, float y_pos, const char* playerName);
	SDL_FRect& getRect();
	void movePlayer1();
	void movePlayer2();
	void setX(float xPos);
	void setY(float xPos);
	float getX();
	float getY();
	void boundaryChecker();
};