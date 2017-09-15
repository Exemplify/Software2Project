#ifndef GAME_OBJ_H
#define GAME_OBJ_H
#include <string>
#include "../Vector2D.hpp"

class GameObject
{
public:
	virtual void Start();
	virtual void Update();
	bool isActive() {return _active;}
	virtual bool HasGraphic(){return false;}
protected:
	Vector2D<double> position;
	bool _active;
};

#endif