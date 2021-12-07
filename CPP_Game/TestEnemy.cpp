#include "TestEnemy.h"

namespace ENEMY_CONSTS
{
	constexpr float WALK_SPEED = 0.1f;
}

TestEnemy::TestEnemy()
{
	facingPosition_ = Direction::DOWN;
	changeInXPos = 0;
	changeInYPos = 0;

	chaseState = false;
	isAttacking = false;
	isMoving = false;

}

TestEnemy::~TestEnemy()
{
	/*delete &changeInXPos;
	delete &changeInYPos;*/
	//delete &facingPosition_;
}

TestEnemy::TestEnemy(Graphics& graphics, float x, float y) : SpriteAnimation(graphics, "Assets/Sprites/Skeleton_RedEye.png", 24, 32, 24, 32, x, y, 100)
{
	facingPosition_ = Direction::DOWN;
	graphics.loadImage("Assets/Sprites/Skeleton_RedEye.png");
	this->setupAnimations();
	this->playAnimation("MoveLeft");

}

void TestEnemy::setupAnimations()
{
	this->addAnimation(3, 0, 0, "MoveUp", 24, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 32, "MoveRight", 24, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 64, "MoveDown", 24, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 96, "MoveLeft", 24, 32, Vector2(0, 0));
}

void TestEnemy::animationComplete(string currentAnimation)
{
}

// temp solution for wall collisions
void TestEnemy::wallColliding() {
	this->setChangeInXPos(this->getChangeInXPos() * -5.0);
	this->setChangeInYPos(this->getChangeInYPos() * -5.0);
}

void TestEnemy::update(int elapsedTime, Player& player)
{
	// Movement


		// Enemy Field of View

	//if (Collision::AABB(this->getFieldOfView(), player.getPlayerHitBox()) == true) {
	//	chaseState = true;
	//	isMoving = false;
	//	std::cout << "test" << std::endl;
	//}

	//// Chasing Player
	//if (chaseState) {
	
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

		else if (player.getPlayerYPos() > this->y_)
		{
			this->setChangeInYPos(ENEMY_CONSTS::WALK_SPEED);

			this->playAnimation("MoveDown");
			std::cout << "Greater than y" << std::endl;
		}

		else if (player.getPlayerYPos() < this->y_)
		{
			this->setChangeInYPos(-ENEMY_CONSTS::WALK_SPEED);

			this->playAnimation("MoveUp");
			std::cout << "0" << std::endl;

		}
		SpriteAnimation::update(elapsedTime);

	//}



}

void TestEnemy::draw(Graphics& graphics)
{
	SpriteAnimation::draw(graphics, this->x_, this->y_);
}
