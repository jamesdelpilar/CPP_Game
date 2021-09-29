#include "Sprite.h"

Sprite::Sprite() 
{
}

Sprite::Sprite(Graphics&graphics, const string &filePath, int srcX, int srcY, int width, int height,
	float posX, float posY) : x_(posX), y_(posY)
{
	this->srcRect.x = srcX;
	this->srcRect.y = srcY;
	this->srcRect.w = width;
	this->srcRect.h = height;

	this->spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
	if (this->spriteSheet == NULL) {
		std::cout << "Image Load Error" << std::endl;
	}
}

Sprite::~Sprite() 
{
}

void Sprite::draw(Graphics &graphics, int x, int y) 
{
	SDL_Rect destRect = { x, y, this->srcRect.w, this->srcRect.h };
	graphics.blitSurface(this->spriteSheet, &this->srcRect, &destRect);
}

void Sprite::update() 
{
}

