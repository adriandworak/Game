#ifndef globals_h
#define globals_h

#include <SDL.h>
#include <SDL_ttf.h>
#include <fstream>
#include <iostream>
#include <list>
#include <Windows.h>
#include <time.h>
#include "CPlayer.h"
#include "CObstacle.h"
#include "event.h"
#include "menu.h"
#include "globals.h"
#include "cleanmemory.h"
#include "optimizefunc.h"
extern bool timing;
extern bool isrunning, up_pushed;
extern int resolution_x, resolution_y, czas;
extern const int FPS;
extern SDL_Event ev;
extern SDL_Window *window;
extern SDL_Surface *windowSurface;
extern SDL_Texture *texture;
extern SDL_Renderer *Target;
//globals for background
extern SDL_Rect camerRect;
extern SDL_Rect background_position;
extern SDL_Rect background_position2;
extern CPlayer gracz;
extern CGame gra;
extern std::list<CObstacle>Lprzeszkody;
extern std::list<CObstacle>::iterator it;

#endif                                                                                                                                                                                                                                                              