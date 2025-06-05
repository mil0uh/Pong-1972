#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>


class Entity {
private:
	double x, y;
	SDL_Texture* texture;
	SDL_FRect currentFrame;
public:
	Entity(double x, double y, SDL_Texture* texture);
	double getX();
	double getY();
	int getH();
	int getW();
	void setX(double x);
	void setY(double y);
	void setCurrentFrameH(int height);
	void setCurrentFrameW(int width);
	void setCurrentFrameHW(int width, int height);
	SDL_FRect& getCurrentFrame();
	SDL_Texture* getTexture();

};