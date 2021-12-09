#include "Health.h"

Health::Health()
{
	maxHP = 3;
	HP = maxHP;
}

Health::Health(int hitpoints)
{
	maxHP = hitpoints;
	HP = maxHP;
}

Health::~Health()
{}

void Health::Deduct(int damagePoints)
{
	if (HP > 0) {
		HP -= damagePoints;
	}
	if (HP <= 0) {
		isDead = true;
	}
}

void Health::Replanish(int damagePoints)
{
	if (HP < maxHP) {
		HP += damagePoints;
	}
}

void Health::Increase()
{
	maxHP += 1;
}