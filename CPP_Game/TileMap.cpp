#include "TileMap.h"

TileMap::TileMap()
{
	background_ = nullptr;
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

	////.tmx file
	//XMLDocument doc;
	//std::stringstream ss;

	//// Loads .tmx file in the Asset folder
	//ss << "Assets/TileMap/" << mapName << ".tmx";
	//doc.LoadFile(ss.str().c_str());

	//XMLElement* mapNode = doc.FirstChildElement("map");

	//// Storing width and height in size_ 
	//int width, height;
	//mapNode->QueryIntAttribute("width", &width);
	//mapNode->QueryIntAttribute("height", &height);
	//this->size_ = Vector2(width, height);

	//// Storing width and height of the tiles in tileSize_
	//int tileWidth, tileHeight;
	//mapNode->QueryIntAttribute("tilewidth", &tileWidth);
	//mapNode->QueryIntAttribute("tileheight", &tileHeight);
	//this->tileSize_ = Vector2(tileWidth, tileHeight);

	////Loading the Tilesets
	//XMLElement* pTileset = mapNode->FirstChildElement("tileset");
	//if (pTileset != nullptr)
	//{
	//	while (pTileset)
	//	{
	//		int firstGid;
	//		const char* source = pTileset->FirstChildElement("image")->Attribute("source");
	//		char* path;
	//		std::stringstream ss;
	//		ss << "Assets/TileMap/" << source;
	//		pTileset->QueryIntAttribute("firstgid", &firstGid);
	//		SDL_Texture* tex = SDL_CreateTextureFromSurface(graphics.getRenderer(),
	//			graphics.loadImage(ss.str()));
	//		this->tileSets_.push_back(Tileset(tex, firstGid));

	//		pTileset = pTileset->NextSiblingElement(("tileset"));
	//	}
	//}

	//// Loading TileMap layers
	//XMLElement* pLayer = mapNode->FirstChildElement("layer");
	//if (pLayer != nullptr)
	//{
	//	while (pLayer)
	//	{
	//		// Loading DATA	ELEMENT
	//		XMLElement* pData = pLayer->FirstChildElement("data");
	//		if (pData != nullptr)
	//		{
	//			while (pData)
	//			{
	//				pData = pData->NextSiblingElement("data");
	//			}

	//			// Loading TILE ELEMENT
	//			XMLElement* pTile = pData->FirstChildElement("tile");
	//			if (pTile != nullptr)
	//			{
	//				int tileCounter = 0;
	//				while (pTile)
	//				{
	//					//Each tile is being build | If gid is 0, tiles will not be drawn
	//					if (pTile->IntAttribute("gid") == 0)
	//					{
	//						tileCounter++;
	//						if (pTile->NextSiblingElement("tile"))
	//						{
	//							pTile = pTile->NextSiblingElement("tile");
	//							continue;
	//						}
	//						else
	//						{
	//							break;
	//						}
	//					}

	//					// Get tileset
	//					int gid = pTile->IntAttribute("gid");
	//					Tileset tls;
	//					for (int i= 0; i < this->tileSets_.size(); i++)
	//					{
	//						if (this->tileSets_[i].firstGid <= gid)
	//						{
	//							tls = this->tileSets_.at(i);
	//							break;
	//						}
	//					}
	//					pTile = pTile->NextSiblingElement("tile");
	//				}
	//			}
	//		}
	//		pLayer = pLayer->NextSiblingElement("layer");
	//	}
	//}
}

void TileMap::update(int elapsedTime)
{
};

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

