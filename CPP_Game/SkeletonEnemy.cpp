#include "SkeletonEnemy.h"

SkeletonEnemy::SkeletonEnemy()
{
	
}

SkeletonEnemy::SkeletonEnemy(Graphics& graphics, Vector2 spawnPoint) :
	BaseEnemy(graphics, "Assets/Sprites/PlayerMovement.png", 64, 64, 64, 64, 
		spawnPoint, 100 ), startingXPos(spawnPoint.x), startingYPos(spawnPoint.y), enemyMovementLeft(false)
{
	this->setupAnimations();
	this->playAnimation("MoveLeft");
}

void SkeletonEnemy::update(int elapsedTime, Player& player)
{
	// Movement
	//this->x_ += this->enemyMovementLeft ? -0.2 : 0.2;
	/*if (this->x_ > (this->startingXPos + 20) || this->x_ < this->startingXPos - 20)
	{
		this->enemyMovementLeft = !this->enemyMovementLeft;
	}*/
	/*if (player.getChangeInXPos() > this->x_)
	{
		this->x_ += 1;
	}

	if (player.getChangeInYPos() > this->y_)
	{
		this->y_ += 1;
	}

	if (player.getChangeInXPos() < this->x_)
	{
		this->x_ -= 1;
	}

	if (player.getChangeInYPos() < this->y_)
	{
		this->y_ -= 1;
	}*/

	if (player.getChangeInXPos() > this->x_)
	{
		this->x_ += 0.2f;
	}

	if (player.getChangeInXPos() < this->x_)
	{
		this->x_ -= 0.2f;
	}

	if (player.getChangeInYPos() > this->y_)
	{
		this->y_ += 0.2f;
	}


	if (player.getChangeInYPos() < this->y_)
	{
		this->y_ -= 0.2f;
	}
	BaseEnemy::update(elapsedTime, player);
}

void SkeletonEnemy::draw(Graphics& graphics)
{
	BaseEnemy::draw(graphics);
}

void SkeletonEnemy::animationComplete(string currentAnimation)
{
}

void SkeletonEnemy::setupAnimations()
{
	this->addAnimation(4, 0, 64, "MoveLeft", 64, 64, Vector2(0, 0));
}


