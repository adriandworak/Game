#ifndef optimize
#define optimize
#include <SDL.h>
#include <string>
SDL_Surface *optimizedSurface(std::string filePath, SDL_Surface *windowSurface);
SDL_Texture *LoadTexture(std::string filePath, SDL_Renderer *rendererTarget);
#endif optimize