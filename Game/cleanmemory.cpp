#include "globals.h"
#include <SDL.h>
#include <SDL_image.h>
void clean()
{
	SDL_FreeSurface(windowSurface);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(Target);
	SDL_Quit(); 
	TTF_Quit();
	IMG_Quit();
}