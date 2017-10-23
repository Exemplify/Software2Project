#ifndef MOVABLE_OBJECT_H
#define MOVABLE_OBJECT_H

#include "../Vector2D.h"

/**
 * @class MovableInterface
 * @file MovableInterface.h
 * @brief Defines the interfaces for any MovableObject Compositions
 */
class MovableInterface
{
public:
	/**
	 * @brief Constructor used to identify the moveSpeed of the object, direction is defaulted to right
	 * @param moveSpeed
	 */
	MovableInterface(double moveSpeed):
	_movespeed{moveSpeed},
	_direction{Vector2D::right}
	{}
	/**
	 * @brief Changes the Vector2D that is passed in by reference to the appropriate value determined by the implementation
	 * @param currentPosition the current position that is adjusted
	 */
	virtual void Move(Vector2D& currentPosition) = 0;
	/**
	 * @brief Sets the direction to a specific value
	 * @param direction the desired direction
	 */
	void setDirection(const Vector2D& direction) {_direction = direction;}
	
	virtual ~MovableInterface() = default;
protected:
	double _movespeed; /**<The movement speed of the object*/
	Vector2D _direction; /**<The direction that the object moves in*/ 
};

#endif