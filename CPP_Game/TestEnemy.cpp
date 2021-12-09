#include "TestEnemy.h"

#include <cmath>

namespace ENEMY_CONSTS
{
	constexpr float WALK_SPEED = 0.05f;
}

TestEnemy::TestEnemy()
{
	chaseState = false;
	isAttacking = false;
	isMoving = false;
	startingPosY = 0.0f;
	startingPosX = 0.0f;
	hp = Health::Health(1);

	/*facingPosition_ = Direction::DOWN;
	changeInXPos = 0;
	changeInYPos = 0;

	chaseState = false;
	isAttacking = false;
	isMoving = false;*/

}

TestEnemy::~TestEnemy()
{

}

TestEnemy::TestEnemy(Graphics& graphics, Vector2 spawnPoint) :
	BaseEnemy(graphics, "Assets/Sprites/Skeleton_RedEye.png", 24, 32, 24, 32, 
		spawnPoint, 200),
		startingPosX(spawnPoint.x),
		startingPosY(spawnPoint.y),
		isMoving(true),
		chaseState(false),
		isAttacking(false)
{
	/*facingPosition_ = Direction::DOWN;*/
	graphics.loadImage("Assets/Sprites/Skeleton_RedEye.png");
	this->setupAnimations();
}

void TestEnemy::setupAnimations()
{
	this->addAnimation(3, 0, 0, "MoveUp", 24, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 32, "MoveRight", 24, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 64, "MoveDown", 24, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 96, "MoveLeft", 24, 32, Vector2(0, 0));

	this->addAnimation(1, 0, 64, "IdleDown", 24, 32, Vector2(0, 0));
}

void TestEnemy::animationComplete(string currentAnimation)
{
}

// temp solution for wall collisions
void TestEnemy::wallColliding() {
	switch (facingPosition)
	{
	case Direction::LEFT:
		this->setChangeInXPos(ENEMY_CONSTS::WALK_SPEED);
		break;
	case Direction::RIGHT:
		this->setChangeInXPos(-ENEMY_CONSTS::WALK_SPEED);
		break;
	case Direction::UP:
		this->setChangeInYPos(ENEMY_CONSTS::WALK_SPEED);
		break;
	case Direction::DOWN:
		this->setChangeInXPos(-ENEMY_CONSTS::WALK_SPEED);
		break;
	default:
		break;
	}
}

void TestEnemy::update(int elapsedTime, Player& player)
{
	// Movement

		// Enemy Field of View
	std::cout << this->getFieldOfView().x << " " << this->getFieldOfView().y << std::endl;
		if (Collision::AABB(this->getFieldOfView(), player.getPlayerHitBox()) == true) {
			chaseState = true;
			isMoving = false;
		}

		// Chasing Player
		if (chaseState == true) {

			Vector2 direction = Vector2((player.getPlayerXPos() + 16) - this->getPlayerXPos(), (player.getPlayerYPos() + 16) - this->getPlayerYPos());
			float angle = atan2(direction.y, direction.x) * (180 / 3.14);
			if (angle < 135.0f && angle > 45.0f) // up
			{
				this->facingPosition = Direction::UP;
				this->setChangeInYPos(ENEMY_CONSTS::WALK_SPEED);
				this->playAnimation("MoveDown");
			}
			if (angle < 45.0f && angle > -45.0f) // right
			{
				this->facingPosition = Direction::RIGHT;
				this->setChangeInXPos(ENEMY_CONSTS::WALK_SPEED);
				this->playAnimation("MoveRight");
			}
			if (angle > -135.0f && angle < -45.0f) // down
			{
				this->facingPosition = Direction::DOWN;
				this->setChangeInYPos(-ENEMY_CONSTS::WALK_SPEED);
				this->playAnimation("MoveUp");
			}
			if (angle < -135.0f && angle >= -179.0f ||
				angle < 180.0f && angle > 135.0f) // left
			{
				this->facingPosition = Direction::LEFT;
				this->setChangeInXPos(-ENEMY_CONSTS::WALK_SPEED);
				this->playAnimation("MoveLeft");
			}

			//if (player.getPlayerXPos() > this->x_)
			//{
			//	this->setChangeInXPos(ENEMY_CONSTS::WALK_SPEED);

			//	//this->playAnimation("MoveRight");
			//	std::cout << "Greater than x" << std::endl;
			//}

			//else if (player.getPlayerXPos() < this->x_)
			//{
			//	this->setChangeInXPos(-ENEMY_CONSTS::WALK_SPEED);

			//	//this->playAnimation("MoveLeft");
			//	std::cout << "Less than x" << std::endl;
			//}

			//if (player.getPlayerYPos() > this->y_)
			//{
			//	this->setChangeInYPos(ENEMY_CONSTS::WALK_SPEED);
			//	this->playAnimation("MoveDown");
			//	std::cout << "Greater than y" << std::endl;
			//}
			//else if (player.getPlayerYPos() < this->y_)
			//{
			//	this->setChangeInYPos(-ENEMY_CONSTS::WALK_SPEED);
			//	this->playAnimation("MoveUp");
			//	std::cout << "0" << std::endl;
			//}

			if (Collision::AABB(this->getEnemyHitBox(), player.getPlayerHitBox()) == true && isAttacking == false) {
				isAttacking = true;
				player.hp.Deduct(1);
				/*Vector2 knockBack (this->getPlayerXPos() + direction.x, this->getPlayerYPos() + direction.y);
				this->setX(knockBack.x);
				this->setY(knockBack.y);*/
			}
			if (Collision::AABB(this->getEnemyHitBox(), player.getPlayerHitBox()) == false && isAttacking == true) {
				isAttacking = false;
			}
		}
		if (chaseState == false) {
			this->playAnimation("IdleDown");
		}
		BaseEnemy::update(elapsedTime, player);
		SpriteAnimation::update(elapsedTime);

}

void TestEnemy::draw(Graphics& graphics)
{
	SpriteAnimation::draw(graphics, this->x_, this->y_);
}
