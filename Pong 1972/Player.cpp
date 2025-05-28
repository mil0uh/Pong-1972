#include "Player.h"


Player::Player(int x_pos, int y_pos, const char* playerName) : x_pos(x_pos), y_pos(y_pos), playerName(playerName) {

	src.h = 150;
	src.w = 25;
	src.x = x_pos;
	src.y = y_pos;

}

SDL_FRect& Player::getRect() {
	return src;
}

void movePlayer() {
	bool inputs = SDL_GetKeyboardState(NULL);

	// Todo: Figure out if the player classes should be seperate as the input will be arrow keys for player2 and wasd for player1 

}
