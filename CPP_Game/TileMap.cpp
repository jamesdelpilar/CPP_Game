#include "TileMap.h"

TileMap::TileMap()
{
	background_ = 0;
}

TileMap::~TileMap()
{
}

TileMap::TileMap(string mapName, Vector2 spawnPoint, Graphics& graphics) :
	mapName_(mapName), spawnPoint_(spawnPoint), size_(Vector2(0,0))
{
	this->loadTileMap(mapName, graphics);
}

void TileMap::loadTileMap(string mapName, Graphics& graphics)
{
	//Temp Code
	this->background_ = SDL_CreateTextureFromSurface(graphics.getRenderer(),
		graphics.loadImage("Assets/TileMap/TXTilesetGrass.png"));
	
	this->size_ = Vector2(1920, 1080);
}

void TileMap::update(int elapsedTime)
{
}

void TileMap::draw(Graphics& graphics)
{
	//Draw background
	SDL_Rect srcRect = { 0, 0, 256, 256 };
	SDL_Rect destRect;

	//Drawing background by looping it | If .png is too small compared to screen size
	for (int x = 0; x < this->size_.x / 256; x++)
	{
		for (int y = 0; y < this->size_.y / 256; y++)
		{
			destRect.x = x * 256 * globals::SCALE_SPRITE;
			destRect.y = y * 256 * globals::SCALE_SPRITE;
			destRect.w = 256 * globals::SCALE_SPRITE;
			destRect.h = 256 * globals::SCALE_SPRITE;

			graphics.blitSurface(this->background_, &srcRect, &destRect);
		}
	}
}
