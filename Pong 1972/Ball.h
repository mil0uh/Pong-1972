#pragma once
#include "Player.h"
#include <iostream>
#include "Entity.h"

class Ball : public Entity {

private:
	// x and y velocity <Dont know if I will keep these>
	double x_vel; 
	double y_vel;
	double last = 0;
public:
	Ball(double x_pos, double y_pos, double x_vel, double y_vel, SDL_Texture* texture);
	void startBall(int randomNumber);
	bool checkCollision(Player player1, Player player2);
	void ballMovement(Player &player1, Player &player2);
	int originalXval();
	int originalYval();





};