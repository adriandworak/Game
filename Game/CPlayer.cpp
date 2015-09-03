#include "CPlayer.h"
#include "globals.h"
#include "optimizefunc.h"
#include <SDL.h>
void CPlayer::setnewlevel()
{
	V = 0;
	position.x = 100;
	position.y = 20;
	position.w = 75;
	position.h = 75;
}
void CPlayer::setcrash()
{
	position.w=200;
	position.h = 200;
}
int CPlayer::gety()
{
	return position.y;
}

void CPlayer::falling()
{
	position.y -=V;
}
void CPlayer::addV(int add)
{
	V += add;
}
void CPlayer::draw()
{

	fWidth = tWidth / 15;
	fHeight = tHeight;
	object_rect.h = fHeight;
	object_rect.w = fWidth;
	fTime++;
	if (FPS / fTime == 20)
	{
		fTime = 0;
		object_rect.x += fWidth;
		if (object_rect.x >= tWidth)
			object_rect.x = 0;
	}
	SDL_RenderCopy(Target, Image, &object_rect, &position);
}
void CPlayer::texload(std::string filePath)
{
	Image = LoadTexture(filePath, Target);
	SDL_QueryTexture(Image, NULL, NULL, &tWidth, &tHeight);
}
CPlayer::~CPlayer()
{
	SDL_DestroyTexture(Image);
	SDL_DestroyRenderer(Target);
}


CPlayer::CPlayer(int x, int y, int w, int h)
{
	int frameTime = 0;
	position.x = x;
	position.y = y;
	position.h = h;
	position.w = w;
	object_rect.x = object_rect.y = 0;
	SDL_Texture *Image = nullptr;
	SDL_Renderer *Target = nullptr;
}
