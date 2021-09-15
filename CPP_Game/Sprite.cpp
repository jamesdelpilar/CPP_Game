#include "Sprite.h"

Sprite::Sprite() 
{
}

Sprite::Sprite(Graphics&graphics, const string &filePath, int srcX, int srcY, int width, int height,
	float posX, float posY) : x_(posX), y_(posY)
{
	srcRect.x = srcX;
	srcRect.y = srcY;
	srcRect.w = width;
	srcRect.h = height;

	spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
	if (spriteSheet == NULL) {
		std::cout << "Image Load Error" << std::endl;
	}
}

Sprite::~Sprite() 
{
}

void Sprite::draw(Graphics &graphics, int x, int y) 
{
	SDL_Rect destRect = { x, y, srcRect.w, srcRect.h };
	graphics.blitSurface(spriteSheet, &srcRect, &destRect);
}

void Sprite::update() 
{
}

