#pragma once

#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <SDL.h>

#include "BaseEnemy.h"
#include "Globals.h"
#include "Graphics.h"
#include "Player.h"
#include "Tile.h"
#include "tinyxml2.h"


using namespace tinyxml2;

class BaseEnemy;
class Graphics;
class Player;
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
	void update(int elapsedTime, Player &player);
	void draw(Graphics& graphics);

private:
	void loadTileMap(string mapName, Graphics& graphics);
	string mapName_;
	Vector2 spawnPoint_;
	Vector2 size_;
	Vector2 tileSize_;

	SDL_Texture* backgroundTex_;

	std::vector<Tile> tileList_;
	std::vector<Tileset> tilesets_;
	std::vector<BaseEnemy*> enemies;
	
};

//Tileset Structure
struct Tileset
{
	SDL_Texture* Texture;
	int FirstGid;

	Tileset()
	{
		this->FirstGid = -1;
	}

	Tileset(SDL_Texture* texture, int firstGid)
	{
		this->Texture = texture;
		this->FirstGid = firstGid;
	}
};