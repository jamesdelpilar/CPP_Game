#include "Graphics.h"

Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->window, &this->renderer);
	SDL_SetWindowTitle(this->window, "Title of Game");
	//SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->window);
}

SDL_Surface* Graphics::loadImage(const string& filePath)
{
	if (this->spriteSheets.count(filePath) == 0) 
	{
		this->spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return this->spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect)
{
	SDL_RenderCopy(this->renderer, texture, srcRect, destRect);

}

void Graphics::flip()
{
	SDL_RenderPresent(this->renderer);
}

void Graphics::clear()
{
	SDL_RenderClear(this->renderer);
}

SDL_Renderer* Graphics::getRenderer() const
{
	return this->renderer;
}

