#include "BaseEnemy.h"

BaseEnemy::BaseEnemy()
{
	changeInXPos = 0.0f;
	changeInYPos = 0.0f;

	fieldOfView.h = {0};
	fieldOfView.w = {0};
	fieldOfView.x = {0};
	fieldOfView.y = {0};

	enemyHitBox.h = {0};
	enemyHitBox.w = {0};
	enemyHitBox.x = {0};
	enemyHitBox.y = {0};

	facingPosition_ = Direction::LEFT;
				
}

BaseEnemy::BaseEnemy(Graphics& graphics, std::string filePath, int srcX, int srcY, int width, int height,
	Vector2 spawnPoint, int timeToUpdate) :
		SpriteAnimation(graphics, filePath, srcX, srcY, width, height, 
		spawnPoint.x, spawnPoint.y, timeToUpdate),
		facingPosition_(Direction::LEFT),
		changeInYPos(0.0f),
		changeInXPos(0.0f),
		fieldOfView{0,0,0,0},
		enemyHitBox{0,0,0,0}
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

// Wall collisions
void BaseEnemy::wallColliding()
{
	this->setChangeInXPos(this->getChangeInXPos() * -1.0);
	this->setChangeInYPos(this->getChangeInYPos() * -1.0);
}

void BaseEnemy::update(int elapsedTime, Player& player)
{
	this->x_ += this->changeInXPos * elapsedTime;
	this->y_ += this->changeInYPos * elapsedTime;
	this->enemyHitBox = { static_cast<int>(this->x_), static_cast<int>(this->y_), 24, 32 }; 
	this->fieldOfView = { static_cast<int>(this->x_ - 100.0f), static_cast<int>(this->y_ - 100.0f), 124, 132 };
	SpriteAnimation::update(elapsedTime);

}

void BaseEnemy::draw(Graphics& graphics)
{
	SpriteAnimation::draw(graphics, this->x_, this->y_);
}