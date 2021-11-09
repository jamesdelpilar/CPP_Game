#include "BaseEnemy.h"

BaseEnemy::BaseEnemy()
{
	
}

BaseEnemy::BaseEnemy(Graphics& graphics, std::string filePath, int srcX, int srcY, int width, int height,
	Vector2 spawnPoint, int timeToUpdate) :
		SpriteAnimation(graphics, filePath, srcX, srcY, width, height, 
			spawnPoint.x, spawnPoint.y, timeToUpdate),
					facingPosition_(Direction::LEFT)
{
}

BaseEnemy::~BaseEnemy()
{
}



void BaseEnemy::setupAnimations()
{
	
}

void BaseEnemy::animationComplete(string currentAnimation)
{
}

// temp solution for wall collisions
void BaseEnemy::wallColliding()
{
	this->setChangeInXPos(this->getChangeInXPos() * -5.0);
	this->setChangeInYPos(this->getChangeInYPos() * -5.0);
}

void BaseEnemy::update(int elapsedTime, Player& player)
{
	SpriteAnimation::update(elapsedTime);
}

void BaseEnemy::draw(Graphics& graphics)
{
	SpriteAnimation::draw(graphics, this->x_, this->y_);
}