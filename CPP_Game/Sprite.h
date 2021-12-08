#pragma once

#include <iostream>
#include "Globals.h"
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
	void setX(float x) { x_ = x; }
	void setY(float y) { y_ = y; }

protected:
	SDL_Rect srcRect;
	SDL_Texture* spriteSheet;
	float x_, y_;
};

