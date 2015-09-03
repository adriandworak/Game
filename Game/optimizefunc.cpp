#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "globals.h"


SDL_Surface *optimizedSurface(std::string filePath, SDL_Surface *windowSurface_)
{
	SDL_Surface *surface = SDL_LoadBMP(filePath.c_str());
	if (surface == NULL)
		std::cout << "surface load error: " << SDL_GetError << std::endl;
	else
	{
		windowSurface = SDL_ConvertSurface(surface, windowSurface_->format, 0);
		if (optimizedSurface == NULL)
			std::cout << "error " << std::endl;
	}
	SDL_FreeSurface(surface);
	return windowSurface;
}

SDL_Texture *LoadTexture(std::string filePath, SDL_Renderer *rendererTarget)
{
	windowSurface = IMG_Load(filePath.c_str());
	if (windowSurface == NULL)
		std::cout << "surface load error: " << SDL_GetError << std::endl;
	else
	{
		texture = SDL_CreateTextureFromSurface(rendererTarget, windowSurface);
		if (texture == NULL)
			std::cout << "error " << SDL_GetError << std::endl;
	}
	return texture;
}

