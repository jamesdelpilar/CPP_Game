#ifndef HEALTH_H
#define HEALTH_H

class Health
{
public:
	Health();
	Health(int hitpoints);
	~Health();

	void Deduct(int damagePoints);
	void Replanish(int damagePoints);
	void Increase();
	int getHP() { return HP; };
	bool IsDead() { return isDead; }
private:
	int HP;
	int maxHP;
	bool isDead = false;
};
#endif 
