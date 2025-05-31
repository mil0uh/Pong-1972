#include "Ball.h"
#include <iostream>
#include <random>
#include "Player.h"

Ball::Ball(float x_pos, float y_pos, float x_vel, float y_vel) : Player(x_pos,y_pos,"Ball"), x_vel(x_vel), y_vel(y_vel) {
	getRect().h = 30;
	getRect().w = 30;
	getRect().x = x_pos;
	getRect().y = y_pos;

	
}

bool Ball::checkCollision(Player player1, Player player2) {
	bool cond1 = this->getX() + this->getRect().w >= player1.getX();
	bool cond2 = this->getX() <= player1.getX() + player1.getRect().w;
	bool cond3 = this->getY() + this->getRect().h >= player1.getY();
	bool cond4 = this->getY() <= player1.getY() + player1.getRect().h;

	bool condA = this->getX() + this->getRect().w >= player2.getX();
	bool condB = this->getX() <= player2.getX() + player2.getRect().w;
	bool condC = this->getY() + this->getRect().h >= player2.getY();
	bool condD = this->getY() <= player2.getY() + player2.getRect().h;


	if ((cond1 && cond2 && cond3 && cond4)||(condA && condB && condC && condD)) {
		return true;
	}


}


void Ball::startBall(int randomNumber) {
	if (randomNumber == 0) {
		x_vel = 1;
	}
	else {
		x_vel = -1;

	}
}

int Ball::originalXval() {
	return 30;
}
int Ball::originalYval() {
	return 0;
}

void Ball::ballMovement(Player &player1, Player &player2) {
	std::cerr << "Player 1 Score " << player1.getPlayer1Score() << "," << " Player 2 Score " << player2.getPlayer2Score() << std::endl;
	Uint64 now = SDL_GetTicks();
	float deltaTime = (now - last) / 1000.0f;
	last = now;
	double speed = 200.0f;
	float relativeIntersectY;
	float normalizeRelativeIntersectionY;
	float bounceAngle;
	this->setX(this->getRect().x + deltaTime * speed * x_vel);
	this->setY(this->getRect().y + deltaTime * speed * y_vel);

	

	if (this->checkCollision(player1, player2) == 1 ) {
		
		x_vel = -x_vel;
		y_vel = x_vel;
		
	}


	if (this->getY() < 0) {
		
		y_vel = -y_vel;
	}

	if (this->getY() > 720) {
		
		y_vel = -y_vel;
	}

	if (this->getX() >= 1280) {
		this->setX(640);
		this->setY(360);
		x_vel = -x_vel;
		y_vel = this->originalYval();
		player1.updatePlayer1Score();
	}

	if (this->getX() <= 0) {
		this->setX(640);
		this->setY(360);
		x_vel = -x_vel;
		y_vel = this->originalYval();
		player2.updatePlayer2Score();
	}
	


}