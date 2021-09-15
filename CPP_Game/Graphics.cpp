#include "Graphics.h"

Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(globals::screenWidth, globals::screenHeight, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "Title of Game");
	//SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(window);
}

SDL_Surface* Graphics::loadImage(const string& filePath)
{
	if (spriteSheets.count(filePath) == 0) 
	{
		spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect)
{
	SDL_RenderCopy(renderer, texture, srcRect, destRect);

}

void Graphics::flip()
{
	SDL_RenderPresent(renderer);
}

void Graphics::clear()
{
	SDL_RenderClear(renderer);
}

SDL_Renderer* Graphics::getRenderer() const
{
	return renderer;
}

