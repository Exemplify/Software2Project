#ifndef GAME_OBJ_H
#define GAME_OBJ_H
#include "../BackEndSystems/Input.h"
#include <string>
#include "../Vector2D.hpp"
#include <memory>

class GameObject: public std::enable_shared_from_this<GameObject>
{
public:
	GameObject() {}
	GameObject(Vector2D<double> startingPosition): 
	_position{startingPosition}
	{}
	virtual void Start() {}
	virtual void Update() {}
	bool isActive() {return _active;}
	virtual bool HasGraphic(){return false;}
	Vector2D<double> getPosition() const {return _position;}
	void setActive(bool active_state) {_active = active_state;} 
	virtual ~GameObject(){}
protected:
	Vector2D<double> _position;
	bool _active = true;
};

#endif