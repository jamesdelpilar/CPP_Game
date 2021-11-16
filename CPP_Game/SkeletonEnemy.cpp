#include "SkeletonEnemy.h"

SkeletonEnemy::SkeletonEnemy()
{
	
}

SkeletonEnemy::SkeletonEnemy(Graphics& graphics, Vector2 spawnPoint) :
	BaseEnemy(graphics, "Assets/Sprites/Skeleton_RedEye.png", 24, 32, 24, 32, 
		spawnPoint, 200 )
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
		std::cout << "Greater than x" << std::endl;
	}

	if (player.getPlayerXPos() < this->x_)
	{
		this->x_ -= 0.2f;
		std::cout << "Less than x" << std::endl;
	}

	if (player.getPlayerYPos() > this->y_)
	{
		this->y_ += 0.2f;
		//this->playAnimation("MoveDown");
		std::cout << "Greater than y" << std::endl;
	}


	if (player.getPlayerYPos() < this->y_)
	{
		this->y_ -= 0.2f;
		//this->playAnimation("MoveUp");
		std::cout << "Less than y" << std::endl;

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
	this->addAnimation(3, 0, 0, "MoveUp", 24, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 32, "MoveRight", 24, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 64, "MoveDown", 24, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 96, "MoveLeft", 24, 32, Vector2(0, 0));

}


