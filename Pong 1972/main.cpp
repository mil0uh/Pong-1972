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

	// Game loop condition
	bool gameLoop = true;

	// Event Handler
	SDL_Event event;

	Player Player1 = Player(100, 285, "Player");
	Player Player2 = Player(1180, 285, "Other Player");
	Ball myBall = Ball(640, 360, 30, 0);



	int randomNumber = generateNumber(); // Generating random number in the range [0,1]
	myBall.startBall(randomNumber);

	while (gameLoop) {
		

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				gameLoop = false;
			}
		}


		window.clearWindow();
		// Rendering Players and Ball
		window.render(Player1);
		window.render(Player2);
		window.render(myBall,255,0,0,255);

		// Checks randomly generated number and moves the ball left or right
		// Moving player 1 and 2 while checking if they are within the 1280x720 boundary
		myBall.ballMovement(Player1, Player2);
		Player1.movePlayer1();
		Player1.boundaryChecker();
		Player2.movePlayer2();
		Player2.boundaryChecker();
		 
		

		// Drawing the objects
		window.present();
	


	}

	window.destroyWindow();



}