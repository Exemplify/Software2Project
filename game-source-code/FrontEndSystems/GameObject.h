#ifndef GAME_OBJ_H
#define GAME_OBJ_H
#include <string>
#include "../Vector2D.hpp"

class GameObject
{
public:
    	GameObject() {}
	virtual void Start() {}
	virtual void Update() {}
	bool isActive() {return _active;}
	virtual bool HasGraphic(){return false;}
	Vector2D<double> getPosition() const {return _position;}
	void setActive(bool active_state) {_active = active_state;} 
protected:
	Vector2D<double> _position;
	bool _active;
};

#endif