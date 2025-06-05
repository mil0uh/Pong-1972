#include "Player.h"
#include "WindowMaker.h"


Player::Player(double x_pos, double y_pos, const char* playerName,SDL_Texture* texture) : x_pos(x_pos), y_pos(y_pos), playerName(playerName), Entity(x_pos,y_pos,texture) {



}



void Player::movePlayer1() {

	Uint64 now = SDL_GetTicks();
	double deltaTime = (now - last) / 1000.0f;
	last = now;
	double speed = 450.0f;

	const bool* inputs = SDL_GetKeyboardState(NULL);

	if (inputs[SDL_SCANCODE_W]) {
		this->setY(this->getY() - speed * deltaTime);
	}

	if (inputs[SDL_SCANCODE_S]) {
		this->setY(this->getY() + speed * deltaTime);
	}


}


void Player::movePlayer2() {

	Uint64 now = SDL_GetTicks();
	double deltaTime = (now - last) / 1000.0f;
	last = now;
	double speed = 300.0f;

	const bool* inputs = SDL_GetKeyboardState(NULL);

	if (inputs[SDL_SCANCODE_UP]) {
		this->setY(this->getY() - speed * deltaTime);
	}

	if (inputs[SDL_SCANCODE_DOWN]) {
		this->setY(this->getY() + speed * deltaTime);
	}


}


void Player::boundaryChecker() {
	if (this->getY() < 0) { this->setY(0); };
	if (this->getY() > 720 - this->getCurrentFrame().h) {this->setY(720 - this->getCurrentFrame().h);}
}


void Player::updatePlayer1Score() {
	player1_score += 1;
}

void Player::updatePlayer2Score() {
	player2_score += 1;
}

int Player::getPlayer1Score() {
	return player1_score;
}

int Player::getPlayer2Score() {
	return player2_score;
}
	