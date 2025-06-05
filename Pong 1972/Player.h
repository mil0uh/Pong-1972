#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include "Entity.h"

class Player : public Entity {
private:
	int player1_score = 0;
	int player2_score = 0;
	SDL_FRect src;
	double x_pos;
	double y_pos;
	Uint64 last = 0;
	const char* playerName;
public:
	Player(double x_pos, double y_pos, const char* playerName, SDL_Texture* texture);
	void movePlayer1();
	void movePlayer2();
	void boundaryChecker();
	void updatePlayer1Score();
	void updatePlayer2Score();
	int getPlayer1Score();
	int getPlayer2Score();
};