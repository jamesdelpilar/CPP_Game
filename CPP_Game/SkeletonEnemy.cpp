#include "SkeletonEnemy.h"

SkeletonEnemy::SkeletonEnemy()
{
	
}

SkeletonEnemy::SkeletonEnemy(Graphics& graphics, Vector2 spawnPoint) :
	BaseEnemy(graphics, "Assets/Sprites/PlayerMovement.png", 64, 64, 64, 64, 
		spawnPoint, 100 )
{
	this->setupAnimations();
	this->playAnimation("MoveLeft");
}

void SkeletonEnemy::update(int elapsedTime, Player& player)
{
	// Movement

	if (player.getPlayerXPos() > this->x_)
	{
		this->x_ += 0.2f;
	}

	if (player.getPlayerXPos() < this->x_)
	{
		this->x_ -= 0.2f;
	}

	if (player.getPlayerYPos() > this->y_)
	{
		this->y_ += 0.2f;
	}


	if (player.getPlayerYPos() < this->y_)
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


