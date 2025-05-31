#include "Player.h"
#include "WindowMaker.h"


Player::Player(float x_pos, float y_pos, const char* playerName) : x_pos(x_pos), y_pos(y_pos), playerName(playerName) {

	src.h = 150;
	src.w = 25;
	src.x = x_pos;
	src.y = y_pos;

}

SDL_FRect& Player::getRect() {
	return src;
}

float Player::getX() {
	return src.x;
}

float Player::getY() {
	return src.y;
}

void Player::setX(float xPos) {
	src.x = xPos;
}

void Player::setY(float yPos) {
	src.y = yPos;
}

void Player::movePlayer1() {

	Uint64 now = SDL_GetTicks();
	float deltaTime = (now - last) / 1000.0f;
	last = now;
	float speed = 300.0f;

	const bool* inputs = SDL_GetKeyboardState(NULL);

	if (inputs[SDL_SCANCODE_UP]) {
		this->setY(this->getY() - speed * deltaTime);
	}

	if (inputs[SDL_SCANCODE_DOWN]) {
		this->setY(this->getY() + speed * deltaTime);
	}


}


void Player::movePlayer2() {

	Uint64 now = SDL_GetTicks();
	float deltaTime = (now - last) / 1000.0f;
	last = now;
	float speed = 300.0f;

	const bool* inputs = SDL_GetKeyboardState(NULL);

	if (inputs[SDL_SCANCODE_W]) {
		this->setY(this->getY() - speed * deltaTime);
	}

	if (inputs[SDL_SCANCODE_S]) {
		this->setY(this->getY() + speed * deltaTime);
	}


}


void Player::boundaryChecker() {
	if (this->getY() < 0) { this->setY(0); };
	if (this->getY() > 570) { this->setY(720 - this->src.h); }




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
	