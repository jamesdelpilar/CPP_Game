//#include "Enemy.h"
//
//Enemy::Enemy()
//{
//	changeInXPos = 0;
//	changeInYPos = 0;
//	facingPosition_ = LEFT;
//}
//
//Enemy::~Enemy()
//{
//}
//
//Enemy::Enemy(Graphics& graphics, float x, float y) : SpriteAnimation(graphics, "Assets/Sprites/LinkSprite.png", 0, 0, 21, 27, x, y, 100)
//{
//	graphics.loadImage("Assets/Sprites/LinkSprite.png");
//	this->setupAnimations();
//	//this->playAnimation("MoveBackward");
//}
//
//void Enemy::setupAnimations()
//{
//	this->addAnimation(1, 0, 0, "IdleForward", 21, 26, Vector2(0, 0));
//	this->addAnimation(1, 0, 81, "IdleLeft", 21, 25, Vector2(0, 0));
//	this->addAnimation(1, 0, 54, "IdleRight", 20, 26, Vector2(0, 0));
//	this->addAnimation(1, 0, 0, "IdleBackward", 21, 27, Vector2(0, 0));
//
//	this->addAnimation(7, 0, 0, "MoveUp", 21, 26, Vector2(0, 0));
//	this->addAnimation(7, 0, 81, "MoveLeft", 21, 25, Vector2(0, 0));
//	this->addAnimation(7, 0, 54, "MoveRight", 21, 25, Vector2(0, 0));
//	this->addAnimation(7, 0, 27, "MoveDown", 21, 27, Vector2(0, 0));
//
//	this->addAnimation(3, 0, 137, "AttackUp", 25, 35, Vector2(0, 0));
//	this->addAnimation(3, 0, 197, "AttackLeft", 35, 25, Vector2(0, 0));
//	this->addAnimation(3, 0, 173, "AttackRight", 35, 25, Vector2(0, 0));
//	this->addAnimation(3, 0, 222, "AttackDown", 25, 35, Vector2(0, 0));
//}
//
//void Enemy::animationComplete(string currentAnimation)
//{
//}
//
//// temp solution for wall collisions
//void Enemy::wallColliding()
//{
//	this->setChangeInXPos(this->getChangeInXPos() * -5.0);
//	this->setChangeInYPos(this->getChangeInYPos() * -5.0);
//}
//
//void Enemy::update(float elapsedTime)
//{
//	this->x_ += this->changeInXPos * elapsedTime;
//	this->y_ += this->changeInYPos * elapsedTime;
//	this->playerHitBox = { static_cast<int>(this->x_), static_cast<int>(this->y_), 32, 32 }; //////////
//	SpriteAnimation::update(elapsedTime);
//}
//
//void Enemy::draw(Graphics& graphics)
//{
//	SpriteAnimation::draw(graphics, this->x_, this->y_);
//}