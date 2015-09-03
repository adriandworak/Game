#include <SDL.h>
#include "globals.h"
CGame::CGame()
{
	points = mode = choose = 0;
	crash = false;
	win=true;
	SDL_Texture *Background_tex;
	SDL_Surface *TextSurface;
	SDL_Texture *Display;
	TTF_Font *font;
}
void CGame::setchoose(int choose_)
{
	choose = choose_;
}
void CGame::add_point()
{
	points += 1;
}
void CGame::losowanie(std::string texture)
{
	if (Lprzeszkody.empty())
	for (int a = 0; a <25; a++)
		make_new_obstacle(texture);
	if (Lprzeszkody.size() == 25)
	for (it = Lprzeszkody.begin(); it != Lprzeszkody.end(); ++it)
	{
		if (it->getposx() < -20)
			it->losowanie();
	}
}
void CGame::make_new_obstacle(std::string texture)
{
	CObstacle *new_obstacle = new CObstacle();
	new_obstacle->losowanie();
	new_obstacle->texload(texture);
	Lprzeszkody.push_back(*new_obstacle);
}
void CGame::load_media(std::string background)
{

	if (!media_loaded)
	{
		Background_tex = LoadTexture(background, Target);
		gracz.texload("plane.png");
	}
	media_loaded = true;
}
void CGame::drawing()
{
		 SDL_RenderClear(Target);
		 move_background();
		 for (it = Lprzeszkody.begin(); it != Lprzeszkody.end(); ++it)
		 {
			 it->draw();
		 }
		 display_text(0,resolution_y-70,30,"Meters: ",to_string(points/10));
		 gracz.draw();
		 SDL_RenderPresent(Target);
}
void CGame::falling()
{
	if (!crash)
	{
		if (up_pushed)
			gracz.addV(1);
		else
			gracz.addV(-1);
		gracz.falling();
	}
}
bool CGame::detection()
{
	for (it = Lprzeszkody.begin(); it != Lprzeszkody.end(); it++)
	{
		if (it->getposx() > 100 && it->getposx() < 175 && it != Lprzeszkody.begin() && !crash)
		{
			if (it->getposy() == 1)
			{
				if (it->geth()>gracz.gety())
					return true;
			}
			if (it->getposy() != 1)
			{
				if (gracz.gety() + 75 > it->getposy())
					return true;
			}
		}
	}
}
bool CGame::getcrash()
{
	return crash;
}
void CGame::crash_func()
{
	if (detection())
	{
		gracz.setcrash();
		gracz.texload("explode.png");
		czas = 0;

		crash = true;

	}
}
void CGame::move_background()
{
		SDL_RenderCopy(Target, Background_tex, &camerRect, &background_position);
		if (!crash)
			background_position.x--;
		if (background_position.x <= -resolution_x)
			background_position.x = resolution_x;
		SDL_RenderCopy(Target, Background_tex, &camerRect, &background_position2);
		if (!crash)
			background_position2.x--;
		if (background_position2.x <= -resolution_x)
			background_position2.x = resolution_x;
}
void CGame::display_one_screen(std::string obraz)
{
	Display = LoadTexture(obraz, Target);
	SDL_RenderClear(Target);
	SDL_RenderCopy(Target, Display, &camerRect, &camerRect);
	SDL_RenderPresent(Target);
}
void CGame::round(std::string back, std::string tex, int round_)
{
	if (points == round_ * 10000)
	{
		gracz.setnewlevel();
		timing = false;
		if (points)
		{
			display_one_screen("level_complete.png");
			SDL_Delay(2000);
			points+=25;
		}
	}
		if (!timing)
		{
			up_pushed = false;
			Lprzeszkody.clear();
			media_loaded = false;
 			load_media(back);
			losowanie(tex);
			timing = true;
		}
		if (points < round_*10000 + 6000)
			losowanie(tex);
		if (points > round_ * 10000 + 8000 && points < round_ * 10000 + 10000)
		{
			win = true;
			up_pushed = true;
		}
		move_background();
		drawing();
}
void CGame::game()
{
	if (choose == 1 && mode == 0)
	{
		display_one_screen("select_mode.png");
	}
	else if (choose == 1 && mode ==1)
	{
		if (points <= 10000)
		{
			gra.round("background1.png", "tex1.png", 0);
		}
		if (points <= 20000 && points >=10000)
		{
			gra.round("background2.png", "tex2.png", 1);
		}
		if (points <= 30000 && points >= 20000)
		{
			gra.round("background3.png", "tex3.png", 2);
		}
		if (points == 30000)
		{
			display_one_screen("won.png");
			points++;
			SDL_Delay(5000);
			choose = 0;
			mode = 0;
		}
	}
	else if (choose == 1 && mode == 2)
	{
		if (!points)
		{
		media_loaded = false;
		gracz.setnewlevel();
		Lprzeszkody.clear();
		load_media("arcade_background.png");
		losowanie("arcade_tex.png");
		timing = true;
		}
		losowanie("empty");
		move_background();
		drawing();
	}
	else if (choose == 2)
	{
		display_one_screen("sterowanie.png");
	}
	else if (choose == 3)
	{
		display_one_screen("highscore.png");
		display_text(0, resolution_y - 70, 30, "Meters: ", to_string(points / 10));
	}
	else 
	{
		points = 0;
		crash = false;
		timing = false;
		if (!Lprzeszkody.empty())
			Lprzeszkody.clear();
		display_one_screen("menu.png");
		display_one_screen("menu_.png");
	}
}

int CGame::getchoose()
{
	return choose;
}
void CGame::setmode(int _mode)
{
	mode = _mode;
}
void CGame::display_text(int pos_x, int pos_y, int size, std::string text, std::string text2)
{
	text += text2;
	color = { 255, 255, 255, 255 };
	if (font==NULL)
	font = TTF_OpenFont("font.ttf", size);
	TextRect = { pos_x, pos_y, 0,0 };
	TextSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	texture = SDL_CreateTextureFromSurface(Target, TextSurface);
	SDL_QueryTexture(texture, NULL, NULL, &TextRect.w, &TextRect.h);
	SDL_RenderCopy(Target, texture, NULL, &TextRect);
}
CGame::~CGame()
{
	SDL_FreeSurface(TextSurface);
	SDL_DestroyTexture(Background_tex);
	SDL_DestroyTexture(Display);
	//TTF_CloseFont(font);
	font = nullptr;
}

