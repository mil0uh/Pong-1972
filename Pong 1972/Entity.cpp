#include "Entity.h"
#include <iostream>


Entity::Entity(double x, double y, SDL_Texture* texture) : x(x), y(y), texture(texture){
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.h = 0;
	currentFrame.w = 0;
}

double Entity::getX()
{
	return x;
}

double Entity::getY()
{
	return y;
}

int Entity::getH()
{
	return currentFrame.h;
}

int Entity::getW()
{
	return currentFrame.w;
}

void Entity::setX(double xPos)
{

	x = xPos;

}

void Entity::setY(double yPos)
{
	y = yPos;
}

void Entity::setCurrentFrameH(int height)
{

	currentFrame.h = height;

}

void Entity::setCurrentFrameW(int width)
{
	currentFrame.w = width;

}

void Entity::setCurrentFrameHW(int width, int height)
{
	currentFrame.w = width;
	currentFrame.h = height;

}

SDL_FRect& Entity::getCurrentFrame()
{
	return currentFrame;
}

SDL_Texture* Entity::getTexture()
{
	return texture;
}
