#include <iostream>
#include <SDL3/SDL.h>




int main() {

	SDL_Window* window;
	SDL_Renderer* renderer;

	// Creating instance of 1280x720 window 
	SDL_CreateWindowAndRenderer("Pong 1972", 1280, 720, SDL_WINDOW_OPENGL, &window, &renderer);
	// Game loop condition
	bool gameLoop = true;
	// Variable to check for inputs such as closing the window
	SDL_Event event;

	while (gameLoop) {
		

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				gameLoop = false;
			}
		}



	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();


}