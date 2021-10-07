#pragma once

#include <iostream>
#include <string>
#include <sddl.h>
#include "Globals.h"
#include "Graphics.h"

class Graphics;
struct SDL_Texture;

using std::string;

class TileMap
{
public:
	TileMap();
	~TileMap();
	TileMap(string mapName, Vector2 spawnPoint, Graphics& graphics);
	void update(int elapsedTime);
	void draw(Graphics& graphics);

private:
	void loadTileMap(string mapName, Graphics& graphics);
	string mapName_;
	Vector2 spawnPoint_;
	Vector2 size_;
	SDL_Texture *background_;
};

