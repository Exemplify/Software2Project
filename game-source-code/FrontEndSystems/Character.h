#ifndef CHARACTER_H
#define CHARACTER_H

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
	void setMoveSpeed(double moveSpeed) {_moveSpeed = moveSpeed;}
private:
	int _health;
	double _moveSpeed;
};


#endif 