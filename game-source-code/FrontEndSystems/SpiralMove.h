#ifndef SPIRAL_MOVE_H
#define SPIRAL_MOVE_H
#include "MovableInterface.h"
#include "../Vector2D.h"

/**
 * @class SpiralMove
 * @brief Used to move a GameObject in a spiral originating from the centre of the screen
 */
class SpiralMove: public MovableInterface
{
public:
	/**
	 * @brief Constructs a SpiralMove object with the specific speeds defined
	 * @param radialSpeed the speed that the object moves radially outwards from the centre is defined
	 * @param angularSpeed the speed that the object rotates around the centre is defined 
	 */
	SpiralMove(const double& radialSpeed, const double& angularSpeed);
	/**
	 * @brief overrides the pure virtual function from MoveInterface
	 * @param currentPosition Referenced Vector2D object for the current position that is then adjusted accordingly
	 */
	virtual void Move(Vector2D& currentPosition) override;
	
	virtual ~SpiralMove() = default;
private:
	double _angularSpeed; /**<The speed that the object rotates around the centre of the screen*/
	
};
#endif