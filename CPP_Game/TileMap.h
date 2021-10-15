#pragma once

#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <SDL.h>
#include "Globals.h"
#include "Graphics.h"
#include "Tile.h"
#include "tinyxml2.h"

using namespace tinyxml2;

class Graphics;
struct SDL_Texture;
struct SDL_Rect;
struct Tileset;

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
	Vector2 tileSize_;
	//std::vector<Tile> tileList_;
	//std::vector<Tileset> tileSets_;

	SDL_Texture *background_;

	//Tileset Structure
	/*struct Tileset
	{
		SDL_Texture* texture;
		int firstGid;

		Tileset()
		{
			texture = nullptr;
			this->firstGid = -1;
		}

		Tileset(SDL_Texture* texture, int firstGid)
		{
			this->texture = texture;
			this->firstGid = firstGid;
		}
	};*/

	
};

