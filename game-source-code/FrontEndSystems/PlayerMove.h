#ifndef PLAYER_MOVE_H
#define PLAYER_MOVE_H
#include "MovableInterface.h"

/**
 * @class PlayerMove
 * @brief PlayerMove is responsible for determining how the Player Object moves.
 * @details PlayerMove checks for an input from the user then changes the position 
 * 
 */
class PlayerMove : public MovableInterface
{
public:
	/**
	 * @brief Constructs the PlayerMove object with a desired speed
	 * @param moveSpeed The desired movement speed for the player
	 */
	PlayerMove(double moveSpeed);
	/**
	 * @brief Moves the provided Vector2D in a circle based on input from the user
	 * @param currentPosition
	 */
	virtual void Move(Vector2D& currentPosition) override;

private:
	/**
	 * @brief determines the direction of movement based off of the user input
	 * @return returns an integer of -1,0,1 depending on the users input
	 */
	int determineMoveDirection();
};

#endif