#ifndef SIZE_REDUCTION_H
#define SIZE_REDUCTION_H
#include "../Vector2D.h"


class SizeReduction
{
public:
	SizeReduction() {}
	SizeReduction(const double& max_distance, const xyVector& max_scale, const double& max_collider_size):
	max_distance{max_distance},
	max_scale{max_scale},
	max_collider_size{max_collider_size}
	{}
	void ReduceSize(const Vector2D& position, xyVector& scale, double& colliderSize)
	{
		auto radius = position.getRTVector().r;
		auto distance_ratio = radius/max_distance + minimumRatio;
		if(distance_ratio > 1)
			distance_ratio = 1;

		scale.x = max_scale.x * distance_ratio;
		scale.y = max_scale.y * distance_ratio;
		colliderSize = max_collider_size * distance_ratio;
	}
private: 
	double max_distance;
	xyVector max_scale;
	double max_collider_size;
	const double minimumRatio = 0.25;
};

#endif