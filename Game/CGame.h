#ifndef C_game
#define C_game
#include "CObstacle.h"
#include "globals.h"
#include <list>
using namespace std;
class CGame
{
	std::list<std::string>wyniki;
	std::fstream plik;
	int mode,points, choose;
	bool media_loaded;
	bool crash, win;
	// for background
	SDL_Surface *TextSurface;
	SDL_Texture *Background_tex;
	SDL_Texture *Display;
	SDL_Color color;
	TTF_Font *font;
	SDL_Rect TextRect;
public:
	void display_text(int pos_x, int pos_y, int size, std::string text, std::string text2);
	void setmode(int mode_);
	CGame();
	void display_one_screen(std::string obraz);
	void round(std::string back, std::string tex, int round_);
	int getchoose();
	void setchoose(int choose_);
	void add_point();
	void move_background();
	void falling();
	void background();
	bool quit();
	void crash_func();
	void game();
	void level1();
	void level2();
	void level3();
	void drawing();
	void make_new_obstacle(std::string texture);
	void load_media(std::string background);
	void losowanie(std::string texture);
	bool detection();
	bool getcrash();
	~CGame();
};


#endif 