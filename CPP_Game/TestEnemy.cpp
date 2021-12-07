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
	playerHitBox = { static_cast<int>(x_), static_cast<int>(y_), 10, 10 };////////////////////////
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
	//this->playAnimation("MoveDown");

}

void TestEnemy::setupAnimations()
{/*
	this->addAnimation(1, 0, 192, "IdleUp", 64, 64, Vector2(0, 0));
	this->addAnimation(1, 0, 64, "IdleLeft", 64, 64, Vector2(0, 0));
	this->addAnimation(1, 0, 128, "IdleRight", 64, 64, Vector2(0, 0));
	this->addAnimation(1, 0, 0, "IdleDown", 64, 64, Vector2(0, 0));

	this->addAnimation(4, 0, 192, "MoveUp", 64, 64, Vector2(0, 0));
	this->addAnimation(4, 0, 64, "MoveLeft", 64, 64, Vector2(0, 0));
	this->addAnimation(4, 0, 128, "MoveRight", 64, 64, Vector2(0, 0));
	this->addAnimation(4, 0, 0, "MoveDown", 64, 64, Vector2(0, 0));

	this->addAnimation(4, 0, 510, "AttackUp", 64, 64, Vector2(0, 0));
	this->addAnimation(4, 0, 369, "AttackLeft", 64, 64, Vector2(0, 0));
	this->addAnimation(4, 0, 433, "AttackRight", 64, 64, Vector2(0, 0));
	this->addAnimation(4, 0, 305, "AttackDown", 64, 64, Vector2(0, 0));*/

	this->addAnimation(3, 0, 0, "MoveUp", 24, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 32, "MoveRight", 24, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 64, "MoveDown", 24, 32, Vector2(0, 0));
	this->addAnimation(3, 0, 96, "MoveLeft", 24, 32, Vector2(0, 0));
}

void TestEnemy::animationComplete(string currentAnimation)
{
}
//void TestEnemy::moveLeft()
//{
//	this->changeInXPos = -PLAYER_CONSTS::WALK_SPEED;
//	this->playAnimation("MoveLeft");
//	this->facingPosition_ = Direction::LEFT;
//}
//
//void TestEnemy::moveRight()
//{
//	this->changeInXPos = PLAYER_CONSTS::WALK_SPEED;
//	this->playAnimation("MoveRight");
//	this->facingPosition_ = Direction::RIGHT;
//}
//
//void TestEnemy::moveDown()
//{
//	this->changeInYPos = PLAYER_CONSTS::WALK_SPEED;
//	this->playAnimation("MoveDown");
//	this->facingPosition_ = Direction::DOWN;
//}
//
//void TestEnemy::moveUp()
//{
//	this->changeInYPos = -PLAYER_CONSTS::WALK_SPEED;
//	this->playAnimation("MoveUp");
//	this->facingPosition_ = Direction::UP;
//}
//
//void TestEnemy::attackUp()
//{
//	this->playAnimation("AttackUp");
//}
//
//void TestEnemy::attackDown()
//{
//	this->playAnimation("AttackDown");
//}
//
//void TestEnemy::attackLeft()
//{
//	this->playAnimation("AttackLeft");
//}
//
//void TestEnemy::attackRight()
//{
//	this->playAnimation("AttackRight");
//}
//
//
//void TestEnemy::stopMoving(Direction facingPosition)
//{
//	this->changeInXPos = 0.0f;
//	this->changeInYPos = 0.0f;
//
//	switch (facingPosition)
//	{
//	case Direction::LEFT:
//		this->playAnimation("IdleLeft");
//		break;
//	case Direction::RIGHT:
//		this->playAnimation("IdleRight");
//		break;
//	case Direction::UP:
//		this->playAnimation("IdleUp");
//		break;
//	case Direction::DOWN:
//		this->playAnimation("IdleDown");
//		break;
//	default:
//		break;
//	}
//
//}

// temp solution for wall collisions
void TestEnemy::wallColliding() {
	this->setChangeInXPos(this->getChangeInXPos() * -5.0);
	this->setChangeInYPos(this->getChangeInYPos() * -5.0);
}

void TestEnemy::update(float elapsedTime, Player& player)
{
	//this->x_ += this->changeInXPos * elapsedTime;
	//this->y_ += this->changeInYPos * elapsedTime;
	//this->playerHitBox = { static_cast<int>(this->x_), static_cast<int>(this->y_), 32, 32 }; //////////
	//SpriteAnimation::update(elapsedTime);
	//printf("player HP = %d\n", hp.getHP());

	this->playAnimation("MoveDown");

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

			//this->playAnimation("MoveRight");
			std::cout << "Greater than x" << std::endl;
		}

		else if (player.getPlayerXPos() < this->x_)
		{
			this->setChangeInXPos(-ENEMY_CONSTS::WALK_SPEED);

			//this->playAnimation("MoveLeft");
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
			std::cout << "Less than y" << std::endl;

		}
	}
	SpriteAnimation::update(elapsedTime);

}

void TestEnemy::draw(Graphics& graphics)
{
	SpriteAnimation::draw(graphics, this->x_, this->y_);
}
