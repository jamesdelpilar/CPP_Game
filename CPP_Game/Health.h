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
private:
	int HP;
	int maxHP;
};
#endif 
