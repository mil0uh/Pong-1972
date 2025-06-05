#include "Ball.h"
#include <iostream>
#include <random>

#include "Entity.h"

Ball::Ball(double x_pos, double y_pos, double x_vel, double y_vel, SDL_Texture* texture) : Entity(x_pos,y_pos,texture), x_vel(x_vel), y_vel(y_vel) {

}

bool Ball::checkCollision(Player player1, Player player2) {
	bool cond1 = this->getX() + this->getCurrentFrame().w >= player1.getX();
	bool cond2 = this->getX() <= player1.getX() + player1.getCurrentFrame().w;
	bool cond3 = this->getY() + this->getCurrentFrame().h >= player1.getY();
	bool cond4 = this->getY() <= player1.getY() + player1.getCurrentFrame().h;

	bool condA = this->getX() + this->getCurrentFrame().w >= player2.getX();
	bool condB = this->getX() <= player2.getX() + player2.getCurrentFrame().w;
	bool condC = this->getY() + this->getCurrentFrame().h >= player2.getY();
	bool condD = this->getY() <= player2.getY() + player2.getCurrentFrame().h;


	if ((cond1 && cond2 && cond3 && cond4)||(condA && condB && condC && condD)) {
		return true;
	}

	return false;
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
	std::cerr << player1.getPlayer1Score() << "-" << player2.getPlayer2Score() << std::endl;
	Uint64 now = SDL_GetTicks();
	float deltaTime = (now - last) / 1000.0f;
	last = now;
	double speed = 200.0f;
	float relativeIntersectY;
	float normalizeRelativeIntersectionY;
	float bounceAngle;
	this->setX(this->getX() + deltaTime * speed * x_vel);
	this->setY(this->getY() + deltaTime * speed * y_vel);

	

	if (this->checkCollision(player1, player2) == 1 ) {
		
		x_vel = -x_vel;
		y_vel = x_vel;
		
	}


	if (this->getY() < 0) {
		
		y_vel = -y_vel;
	}

	if (this->getY() > 720-30) {
		
		y_vel = -y_vel;
	}

	if (this->getX() > 1280) {
		this->setX(640);
		this->setY(360);
		x_vel = -x_vel;
		y_vel = this->originalYval();
		player1.updatePlayer1Score();
	}

	if (this->getX() < 0) {
		this->setX(640);
		this->setY(360);
		x_vel = -x_vel;
		y_vel = this->originalYval();
		player2.updatePlayer2Score();
	}
	


}