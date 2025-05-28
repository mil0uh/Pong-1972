#include <iostream>
#include <SDL3/SDL.h>
#include "WindowMaker.h"
using namespace std;


int main() {
	// Creating a 1280x720 window
	WindowMaker window = WindowMaker("Pong 1972", 1280, 720);

	Uint64 currentTime = SDL_GetTicks();

	// Game loop condition
	bool gameLoop = true;

	// Event Handler
	SDL_Event event;

	Player testObj = Player(200, 50, "Player");
	Player testObj2 = Player(1080, 50, "Other Player");

	while (gameLoop) {
		

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				gameLoop = false;
			}
		}


		window.clearWindow();
		window.render(testObj);
		window.render(testObj2);

		window.present();
	


	}

	window.destroyWindow();



}