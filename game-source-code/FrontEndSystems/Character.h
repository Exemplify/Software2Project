#ifndef CHARACTER_H
#define CHARACTER_H

// What is this class for, why is it necessaryshould this not be based in the objects themselves?

class Character
{
public:
	Character(){}
	Character(int health, double moveSpeed):
	_health{health},
	_moveSpeed{moveSpeed}
	{}
	int getHealth() {return _health;}
	void setHealth(int health) {_health = health;}
	double getMoveSpeed() {return _moveSpeed;}
private:
	int _health;
	double _moveSpeed;
};


#endif 