#include <iostream>
#include <SDL3/SDL.h>
#include "WindowMaker.h"
#include "Ball.h"
using namespace std;



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
	Ball myBall = Ball(640, 360, 30, 30);

	int randomNumber = myBall.generateNumber(); // Generating random number in the range [0,1]

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
		myBall.startBall(randomNumber); 
		// Moving player 1 and 2 while checking if they are within the 1280x720 boundary
		Player1.movePlayer1();
		Player1.boundaryChecker();
		Player2.movePlayer2();
		Player2.boundaryChecker();

		// Drawing the objects
		window.present();
	


	}

	window.destroyWindow();



}