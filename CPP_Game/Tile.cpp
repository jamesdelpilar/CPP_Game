#include "Tile.h"

Tile::Tile()
{
	tileSet_ = nullptr;
}

Tile::Tile(SDL_Texture* tileset, Vector2 size, Vector2 tilesetPosition, Vector2 position) :
	tileSet_(tileset), size_(size), tilesetPosition_(tilesetPosition),
	position_(Vector2(position.x * globals::SCALE_SPRITE, position.y * globals::SCALE_SPRITE))
{
	
}

void Tile::update(int elapsedTime)
{
}

void Tile::draw(Graphics& graphics) const
{
	SDL_Rect destRect = 
	{ this->position_.x, this->position_.y, this->size_.x * globals::SCALE_SPRITE,
		this->size_.y * globals::SCALE_SPRITE };

	SDL_Rect sourceRect = 
	{ this->tilesetPosition_.x, this->tilesetPosition_.y, this->size_.x, this->size_.y };

	graphics.blitSurface(this->tileSet_, &sourceRect, &destRect);
}
