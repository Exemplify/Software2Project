#ifndef SIZE_REDUCTION_H
#define SIZE_REDUCTION_H
#include "../Vector2D.h"

/**
 * @class SizeReduction
 * @brief USed to reduce the size of an GameObject based off its proximity with the centre of the screen
 */
class SizeReduction
{
public:
	/**
	 * @brief Constructs a SizeReduction Object with the maximum scale and maximum collider size of the GameObject specified
	 * @param max_scale The maximum scale of the GameObject 
	 * @param max_collider_size The maximum collider size of the GameObject
	 */
	SizeReduction( const xyVector& max_scale, const double& max_collider_size);
	/**
	 * @brief Reduces the referenced scale and colliderSize based on the proximity to the center of the screen 
	 * and the maximum scale and collider size provided on construction of the object
	 * @param position The position of the object relative to the origin(Screen centre)
	 * @param scale Referenced scale of the GameObject that is varying its size
	 * @param colliderSize Referenced collider size of the GameObject that is varying its size
	 */
	void ReduceSize(const Vector2D& position, xyVector& scale, double& colliderSize);
private: 
	xyVector max_scale; /**<Maximum scale of that will be set at the maximum distance of the screen*/
	double max_collider_size; /**<Maximum collider size that will be set at the maximum distance of the screen*/
};

#endif