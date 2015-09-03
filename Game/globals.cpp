#include "globals.h"
bool up_pushed, isrunning = true, timing = false;
int resolution_x = 1024;
int resolution_y = 768;
const int FPS = 60;
int choose = 1;
CPlayer gracz(50, 50, 100, 100);
SDL_Window *window = nullptr;
SDL_Texture *texture = nullptr;
SDL_Surface *windowSurface = nullptr;
SDL_Event ev;
SDL_Renderer *Target = nullptr;
SDL_Rect camerRect = { 0, 0, resolution_x, resolution_y };
SDL_Rect background_position = { 0, 0, resolution_x, resolution_y };
SDL_Rect background_position2 = { resolution_x, 0, resolution_x, resolution_y };
std::list<CObstacle>Lprzeszkody;
std::list<CObstacle>::iterator it;
CGame gra;

int czas=NULL;