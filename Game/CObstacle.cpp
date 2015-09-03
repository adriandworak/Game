#include "globals.h"
#include "optimizefunc.h"
#include <SDL.h>
#include "CObstacle.h"
#include <list>
CObstacle::~CObstacle()
{
	SDL_DestroyTexture(Image);
}
bool CObstacle::operator<(CObstacle& a )
{
	return position.x < a.getposx();
}

CObstacle::CObstacle()
{
	int frameTime = 0;
}
int CObstacle::getposx()
{ 
	return position.x;
}
int CObstacle::getposy()
{
	return position.y;
}
int CObstacle::geth()
{
	return position.h;
}
int CObstacle::getw()
{
	return position.w;
}
void CObstacle::push()
{
	position.x-=15;
}
void CObstacle::losowanie()
{
	if (Lprzeszkody.empty())
	{
		position.h = resolution_y / 2;
		position.w = rand() % 10 + 10;
		position.x = resolution_x * 2;
		position.y = 1;
	}
	else
		{
			Lprzeszkody.sort();
			it = Lprzeszkody.end();
			it--;
			// losowanie wys i polozenia
			position.h = resolution_y - it->geth() - rand() % 80 - 200;
			if (it->getposy() > 1)
			{
				position.y = 1;
				while (position.h > resolution_y - 200)
					position.h = resolution_y - it->geth() - rand() % 80 - 200;
			}
			else //  gdy pozycja poprzedniego to 1
			{
				while (position.h > resolution_y - 200)
					position.h = resolution_y - it->geth() - rand() % 80 - 200;
				position.y = (resolution_y - 1) - position.h;
			}
			position.x = it->getposx() + 50;
			position.w = rand() % 10 + 20;
			object_rect.x = rand() & 180;
			object_rect.y = 0;
			object_rect.h = position.h;
			object_rect.w= position.w;
		
		}
}  
void CObstacle::draw()
{
	SDL_RenderCopy(Target, Image, &object_rect, &position);
}
void CObstacle::texload(std::string filePath)
{
	Image = LoadTexture(filePath, Target);
}