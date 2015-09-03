#ifndef Cplayer_h
#define Cplayer_h
#include "CObject.h"
class CPlayer :public CObject
{
	int V = 0;
public:
	CPlayer(int x, int y, int h, int w);
	void setnewlevel();
	void setcrash();
	int gety();
	void addV(int add);
	void falling();
	void draw();
	void texload(std::string filePath);
	~CPlayer();

};
#endif