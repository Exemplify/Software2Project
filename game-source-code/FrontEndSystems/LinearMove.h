#ifndef LIN_MOVE_H
#define LIN_MOVE_H
#include "MovableInterface.h"
#include "../BackEndSystems/GameTime.h"

/**
 * @class LinearMove
 * @brief A basic implementation of the MovableInterface, causes an object to move in a straight line along a specific direction
 */
class LinearMove: public MovableInterface
{
public:
	/**
	 * @brief Constructs the object with a desired movement speed
	 * @param moveSpeed the objects desired movespeed
	 */
	LinearMove(double moveSpeed):
	MovableInterface(moveSpeed)
	{}
	/**
	 * @brief Increases the Vector2D that is passed in by reference along the straight line defined by the direction
	 * @param currentPosition the current position that is adjusted 
	 */
	virtual void Move(Vector2D& currentPosition) override;
	virtual ~LinearMove() = default;

};

#endif 