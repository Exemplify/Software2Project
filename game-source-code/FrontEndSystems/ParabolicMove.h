#ifndef PARABOLIC_MOVE_H
#define PARABOLIC_MOVE_H
#include "MovableInterface.h"

/**
 * @class ParabolicMove
 * @file ParabolicMove.h
 * @brief Complex movement pattern which causes an position to change in a parabolic shape through the origin
 */
class ParabolicMove : public MovableInterface
{
public:
	/**
	 * @brief Constructs a ParabolicMove Object with the specified parameters  
	 * @param parabolic_coefficient the desired coefficient value used to determine the spread of the parabola
	 * @param movespeed the movement speed used to determine how fast a position changes
	 */
	ParabolicMove(const double& parabolic_coefficient, const double& movespeed);
	/**
	 * @brief varies the Vector2D in a parabolic way, by using the equation of a parabola that passes through the origin
	 * @param currentPosition
	 */
	virtual void Move(Vector2D& currentPosition) override;
private:
	double _parabolic_coefficient; /**<The coeficient value used to determine the spread of the parabola*/
	/**
	 * @brief Determines the movespeed of the object based on its proximity to the origin
	 * @param position the current position of the object
	 * @return returns the determined movement speed of the object 
	 */
	double MoveSpeed(const Vector2D& position); 
};
#endif