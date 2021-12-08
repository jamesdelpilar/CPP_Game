#include "TileMap.h"
#include "SkeletonEnemy.h" 

TileMap::TileMap()
{
	backgroundTex_ = nullptr;
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
	//Load .tmx file
	XMLDocument doc;
	std::stringstream ss;
	ss << "Levels/" << mapName << ".tmx"; 
	doc.LoadFile(ss.str().c_str());

	XMLElement* mapNode = doc.FirstChildElement("map");

	//Get the width and the height of the whole map and store it in _size
	int width, height;
	mapNode->QueryIntAttribute("width", &width);
	mapNode->QueryIntAttribute("height", &height);
	this->size_ = Vector2(width, height);

	//Get the width and the height of the tiles and store it in _tileSize
	int tileWidth, tileHeight;
	mapNode->QueryIntAttribute("tilewidth", &tileWidth);
	mapNode->QueryIntAttribute("tileheight", &tileHeight);
	this->tileSize_ = Vector2(tileWidth, tileHeight);

	//Loading the tilesets
	XMLElement* pTileset = mapNode->FirstChildElement("tileset");
	if (pTileset != nullptr)
	{
		while (pTileset)
		{
			int firstgid;
			const char* source = pTileset->FirstChildElement("image")->Attribute("source");
			char* path;
			std::stringstream ss;
			ss << "Levels/" << source;
			pTileset->QueryIntAttribute("firstgid", &firstgid);
			SDL_Texture* tex = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(ss.str()));
			this->tilesets_.push_back(Tileset(tex, firstgid));

			pTileset = pTileset->NextSiblingElement("tileset");
		}
	}

	//Loading the layers
	XMLElement* pLayer = mapNode->FirstChildElement("layer");
	if(pLayer != NULL)
	{
		while (pLayer)
		{
			//Loading "data"
			XMLElement* pData = pLayer->FirstChildElement("data");
			if (pData != NULL)
			{
				while (pData)
				{
					//Loading "tile"
					XMLElement* pTile = pData->FirstChildElement("tile");
					if (pTile != NULL)
					{
						int tileCounter = 0;
						while (pTile)
						{
							//Building each tile
							if (pTile->IntAttribute("gid") == 0)
							{
								tileCounter++;
								if(pTile->NextSiblingElement("tile"))
								{
									pTile = pTile->NextSiblingElement("tile");
									continue;
								}
								else
								{
									break;
								}
							}

							// Grabbing tileset for specific gid
							int gid = pTile->IntAttribute("gid");
							Tileset tls;
							for (int i = 0; i < this->tilesets_.size(); i++)
							{
								if (this->tilesets_[i].FirstGid <= gid)
								{
									//Tileset 
									tls = this->tilesets_.at(i);
									break;
								}
							}

							if (tls.FirstGid == -1)
							{
								// No tileset found
								tileCounter++;
								if (pTile->NextSiblingElement("tile"))
								{
									pTile = pTile->NextSiblingElement("tile");
									continue;
								}
								else
								{
									break;
								}
							}

							// Grabbing tile positions of .tmx
							int xTile = 0;
							int yTile = 0;

							xTile = tileCounter % width;
							xTile *= tileWidth;

							yTile += tileHeight * (tileCounter / width);

							Vector2 finalTilePos = Vector2(xTile, yTile);

							// Calculating the tile's position
							int tilesetWidth, tilesetHeight;
							SDL_QueryTexture(tls.Texture, NULL, NULL, &tilesetWidth, &tilesetHeight);

							int tilesetXTile = gid % (tilesetWidth / tileWidth) - 1;
							tilesetXTile *= tileWidth;

							int tilesetYTile = 0;
							int amount = (gid / (tilesetWidth / tileWidth));
							tilesetYTile = tileHeight * amount;
							Vector2 finalTilesetPos = Vector2(tilesetXTile, tilesetYTile);

							// Build tile and put into tile list
							Tile tile(tls.Texture, Vector2(tileWidth, tileHeight), finalTilesetPos, finalTilePos);
							this->tileList_.push_back(tile);
							tileCounter++;

							pTile = pTile->NextSiblingElement("tile");
						}
					}
					pData = pData->NextSiblingElement("data");
				}
			}
			pLayer = pLayer->NextSiblingElement("layer");
		}
	}

	// Read Enemies in .tmx file
	XMLElement* pObjectGroup = mapNode->FirstChildElement("objectgroup");
	if (pObjectGroup != NULL) 
	{
		while (pObjectGroup) 
		{
			const char* name = pObjectGroup->Attribute("name");
			std::stringstream ss;
			ss << name;

			if (ss.str() == "Enemies") 
			{
				float x, y;
				XMLElement* pObject = pObjectGroup->FirstChildElement("object");
				if (pObject != NULL) 
				{
					while (pObject) 
					{
						x = pObject->FloatAttribute("x");
						y = pObject->FloatAttribute("y");
						const char* name = pObject->Attribute("name");
						std::stringstream ss;
						ss << name;

						if (ss.str() == "Skeleton") 
						{
							this->enemies.push_back(new SkeletonEnemy(graphics, Vector2(std::floor(x) * globals::SCALE_SPRITE,
								std::floor(y) * globals::SCALE_SPRITE)));
						}

						pObject = pObject->NextSiblingElement("object");
					}
				}
			}

			pObjectGroup = pObjectGroup->NextSiblingElement("objectgroup");
		}
	}
}



void TileMap::update(int elapsedTime, Player &player)
{
	for (int i = 0; i < this->enemies.size(); i++) 
	{
		this->enemies.at(i)->update(elapsedTime, player);
	}
};

void TileMap::draw(Graphics& graphics)
{

	for (int i = 0; i < this->tileList_.size(); i++) 
	{
		this->tileList_.at(i).draw(graphics);
	}

	for (int i = 0; i < this->enemies.size(); i++) 
	{
		this->enemies.at(i)->draw(graphics);
	}
}

