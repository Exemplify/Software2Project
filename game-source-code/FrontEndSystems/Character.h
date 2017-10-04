#ifndef CHARACTER_H
#define CHARACTER_H

/// Data Class Must fix, incorporate movement into character, 
/// and make it an interface so that different movement types can be
/// defined. Needs behavior rather than setters and getters

/// What is a Character, player and enemies
/// Character can shoot move and lose health
/// Character composed of a shootComponent, a moveComponent, healthComponent?
/// Character is told when to move, is responsible for setting position of the game object

/// entire class needs to change
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