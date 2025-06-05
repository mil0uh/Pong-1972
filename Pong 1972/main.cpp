#include <iostream>
#include <SDL3/SDL.h>
#include "WindowMaker.h"
#include "Ball.h"
#include <random>
using namespace std;


int generateNumber() {
	std::random_device seed;
	std::mt19937 gen(seed());
	std::uniform_int_distribution<> dist(0, 1);

	int left_or_right = dist(gen);
	return left_or_right;
}



int main() {


	// Creating a 1280x720 window
	WindowMaker window = WindowMaker("Pong 1972", 1280, 720);

	Uint64 currentTime = SDL_GetTicks();

	SDL_Texture* player1Texture = window.loadTexture("Art/Computer.png");
	SDL_Texture* player2Texture = window.loadTexture("Art/Player.png");
	SDL_Texture* boardTexture = window.loadTexture("Art/Board.png");
	SDL_Texture* ballTexture = window.loadTexture("Art/Ball.png");

	// Game loop condition
	bool gameLoop = true;

	// Event Handler
	SDL_Event event;

	Player player1(100, 285, "Player 1", player1Texture);
	Player player2(1180, 285, "Player 2", player2Texture);
	Ball gameBall(640, 300, 2, 0, ballTexture);
	Entity gameBackGround(0, 0, boardTexture);
	
	player2.setCurrentFrameHW(17, 120);
	player1.setCurrentFrameHW(17, 120);
	gameBall.setCurrentFrameHW(30, 30);
	gameBackGround.setCurrentFrameHW(1280, 1080);
	



	int randomNumber = generateNumber(); // Generating random number in the range [0,1]
	

	while (gameLoop) {
		

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				gameLoop = false;
			}
		}


		window.clearWindow();
		// Rendering Players and Ball
		window.render(gameBackGround);
		window.render(gameBall);
		window.render(player1);
		window.render(player2);

		// Checks randomly generated number and moves the ball left or right
		// Moving player 1 and 2 while checking if they are within the 1280x720 boundary
		player1.movePlayer1();
		player1.boundaryChecker();
		player2.movePlayer2();
		player2.boundaryChecker();
		gameBall.ballMovement(player1, player2);

		// Drawing the objects
		window.present();
	


	}

	window.destroyWindow();



}