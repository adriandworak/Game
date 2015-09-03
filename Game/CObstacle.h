#ifndef obstacle_h
#define obstacle_h
#include <SDL.h>
#include "CObject.h"
#include "CGame.h"


class CObstacle :public CObject
{
public:
	int getposx();
	int getposy();
	int getw();
	int geth();
	void push(); // przesuwanie obiektu
	void draw();
	void setx();
	void losowanie();
	CObstacle();
	void texload(std::string filePath);
	bool operator<(CObstacle& a);
	~CObstacle();

};
#endif