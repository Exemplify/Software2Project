#ifndef GAME_OBJ_H
#define GAME_OBJ_H

#include <string>

struct Vector2D
{
	float x;
	float y;
};
class GameObject
{
public:
	virtual void Start();
	virtual void Update();
	bool getActive();
	bool getHasGraphic();
private:
	Vector2D position;
	bool _active;
	bool _hasGraphic;
};

#endif