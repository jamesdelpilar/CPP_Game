#pragma once

#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Globals.h"

using std::map;
using std::string;

struct SDL_Renderer;
struct SDL_Window;

class Graphics
{

public:
	Graphics();
	~Graphics();
	
	SDL_Surface* loadImage(const string &filePath);

	// Draws textures on specific locations of the screen
	void blitSurface(SDL_Texture* src, SDL_Rect* srcRect, SDL_Rect* destRect);
	
	//Rendering to screen
	void flip();

	// Clear to screen
	void clear();

	SDL_Renderer* getRenderer() const;


private:
	SDL_Window* window_;
	SDL_Renderer* renderer_;

	map<string, SDL_Surface*> spriteSheets_;
};

