#include "SkeletonEnemy.h"

namespace ENEMY_CONSTS
{
	constexpr float WALK_SPEED = 0.1f;
}

SkeletonEnemy::SkeletonEnemy()
{
	chaseState = false;
	isAttacking = false;
	isMoving = false;
	startingPosY = 0.0f;
	startingPosX = 0.0f;
}

SkeletonEnemy::SkeletonEnemy(Graphics& graphics, Vector2 spawnPoint) :
	BaseEnemy(graphics, "Assets/Sprites/Skeleton_RedEye.png", 24, 32, 24, 32, 
		spawnPoint, 200),
		startingPosX(spawnPoint.x),
		startingPosY(spawnPoint.y),
		isMoving(true),
		chaseState(false),
		isAttacking(false)
{
	this->setupAnimations();
	this->playAnimation("MoveLeft");
}

void SkeletonEnemy::update(int elapsedTime, Player& player)
{
	// Movement

	// Enemy Field of View

	if (Collision::AABB(this->getFieldOfView(), player.getPlayerHitBox()) == true) {
		chaseState = true;
		isMoving = false;
	}

	// Chasing Player
	if (chaseState) {
		if (player.getPlayerXPos() > this->x_)
		{
			this->setChangeInXPos(ENEMY_CONSTS::WALK_SPEED);

			this->playAnimation("MoveRight");
			std::cout << "Greater than x" << std::endl;
		}

		else if (player.getPlayerXPos() < this->x_)
		{
			this->setChangeInXPos(-ENEMY_CONSTS::WALK_SPEED);

			this->playAnimation("MoveLeft");
			std::cout << "Less than x" << std::endl;
		}

		if (player.getPlayerYPos() > this->y_)
		{
			this->setChangeInYPos(ENEMY_CONSTS::WALK_SPEED);

			this->playAnimation("MoveDown");
			std::cout << "Greater than y" << std::endl;
		}

		else if (player.getPlayerYPos() < this->y_)
		{
			this->setChangeInYPos(-ENEMY_CONSTS::WALK_SPEED);

			this->playAnimation("MoveUp");
			std::cout << "Less than y" << std::endl;

		}

		
	}
	BaseEnemy::update(elapsedTime, player);
	if (Collision::AABB(this->getEnemyHitBox(), player.getPlayerHitBox()) == true && isAttacking == false) {
		isAttacking = true;
		player.hp.Deduct(1);
	}
	if (Collision::AABB(this->getEnemyHitBox(), player.getPlayerHitBox()) == false) {
		isAttacking = false;
	}

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


