#include "Graphics.h"

Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->window_, &this->renderer_);
	SDL_SetWindowTitle(this->window_, "Title of Game");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->window_);
	SDL_DestroyRenderer(this->renderer_);
}

SDL_Surface* Graphics::loadImage(const string& filePath)
{
	if (this->spriteSheets_.count(filePath) == 0) 
	{
		this->spriteSheets_[filePath] = IMG_Load(filePath.c_str());
	}
	else {
		printf("Couldn't load your image");
	}
	return this->spriteSheets_[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect)
{
	SDL_RenderCopy(this->renderer_, texture, srcRect, destRect);

}

void Graphics::flip()
{
	SDL_RenderPresent(this->renderer_);
}

void Graphics::clear()
{
	SDL_RenderClear(this->renderer_);
}

SDL_Renderer* Graphics::getRenderer() const
{
	return this->renderer_;
}

