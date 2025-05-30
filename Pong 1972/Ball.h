#pragma once
#include "Player.h"
#include <iostream>


class Ball : public Player {

private:
	// x and y velocity <Dont know if I will keep these>
	float x_vel; 
	float y_vel;
	float last = 0;
public:
	Ball(float x_pos, float y_pos, float x_vel, float y_vel);
	void startBall(int randomNumber);
	bool checkCollision(Player player1, Player player2);
	void ballMovement(Player player1, Player player2);




};