#pragma once
#include <iostream>
#include "globals.h"
#include "Graphics.h"
class Graphics;

class Sprite
{
public:
	Sprite();
	Sprite(Graphics& graphics, const string& filePath, int srcX, int srcY, int width, int height, float posX, float posY);

	virtual ~Sprite();
	virtual void update();

	void draw(Graphics& graphics, int x, int y);

protected:
	SDL_Rect srcRect;
	SDL_Texture* spriteSheet;
	float x_, y_;

};

