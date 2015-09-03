#include <SDL.h>
#include "globals.h"
#include "optimizefunc.h"
#include "CPlayer.h"

void event()
{
	while (SDL_PollEvent(&ev) != 0)
	{
		if (ev.type == SDL_QUIT)
		{
			isrunning = false;
		}
		else if (ev.type == SDL_KEYDOWN)
		{
			switch (ev.key.keysym.sym)
			{
			case SDLK_KP_ENTER:
				timing = true;
				break;
			case SDLK_ESCAPE:
				if (!gra.getchoose())
					isrunning = false;
				else
				{
					gra.setchoose(0);
					gra.setmode(0);
				}
				break;
			case SDLK_h:
				gra.setchoose(3);
				break;
			case SDLK_t:
				gra.setchoose(2);
				break;
			case SDLK_c:
				gra.setmode(1);
				break;
			case SDLK_a:
				gra.setmode(2);
				break;
			case SDLK_SPACE:
				if (gra.getchoose()==0)
				gra.setchoose(1);
				up_pushed = true;
				break;
			}

		}
		else if (ev.type == SDL_KEYUP)
		if (ev.key.keysym.sym == SDLK_SPACE)
			up_pushed = false;
				
	}
}                                                                                                                                                                                                                                                                                                                                                                                