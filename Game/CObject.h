#ifndef object_h
#define object_h
#include <SDL.h>
#include <iostream>
class CObject
{
protected :
	SDL_Rect object_rect, position;
	SDL_Texture *Image;
	int fHeight, fWidth, tWidth, tHeight, fTime; //f-frame t-texture
	virtual void draw()=0;
	virtual void texload(std::string filePath)=0;
};

#endif //!object

