#include "globals.h"
#include <SDL_ttf.h>
void CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime)
{
		if (timing)
		{
			gra.falling();
			gra.crash_func();
		}
}
void CALLBACK TimerProc2(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime)
{
		for (it = Lprzeszkody.begin(); it != Lprzeszkody.end(); ++it)
		{
			if (!gra.getcrash() && timing)
			{
				it->push();
				gra.add_point();
			}
			if (gra.getcrash())
			{
				czas++;
				if (czas == 1500 )
				{
					gra.display_one_screen("lose.png");
					SDL_Delay(5000);
					gra.setchoose(0);
					gra.setmode(0);
				}
			}
		}
}
int main(int argc, char *argv[])
{
	UINT TimerId = SetTimer(NULL, 1, 20, &TimerProc);
	UINT TimerId2 = SetTimer(NULL, 2, 1, &TimerProc2);
	srand(time(NULL));
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	window = SDL_CreateWindow("YOLO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, resolution_x, resolution_y, SDL_WINDOW_SHOWN);
	Target = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	while (isrunning)
	{
		event();
		gra.game();
	}
	clean();

	return 0;
} 