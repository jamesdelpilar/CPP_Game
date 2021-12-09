#pragma once

#include <SDL.h>
#include "Globals.h"
#include "Graphics.h"

class Graphics;
struct SDL_Texture;

class Tile
{

public:
	Tile();
	Tile(SDL_Texture* tileset, Vector2 size, Vector2 tilesetPosition, Vector2 position);
	void update(int elapsedTime);
	void draw(Graphics& graphics);

protected:
	SDL_Texture *tileset_;
	Vector2 size_;
	Vector2 tilesetPosition_;
	Vector2 position_;
};

