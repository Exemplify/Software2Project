#include "SizeReduction.h"


const unsigned int MAX_GROWTH_DISTANCE = 500;
const double MINIMUM_SHRINK_PERCENTAGE = 0.25;
const unsigned int MAX_RATIO = 1;

SizeReduction::SizeReduction(const xyVector& max_scale, const double& max_collider_size):
max_scale{max_scale},
max_collider_size{max_collider_size}
{}

void SizeReduction::ReduceSize(const Vector2D& position, xyVector& scale, double& colliderSize)
{
	auto radius = position.getRTVector().r;
	auto distance_ratio = radius/MAX_GROWTH_DISTANCE + MINIMUM_SHRINK_PERCENTAGE;
	if(distance_ratio > MAX_RATIO)
		distance_ratio = MAX_RATIO;

	scale.x = max_scale.x * distance_ratio;
	scale.y = max_scale.y * distance_ratio;
	colliderSize = max_collider_size * distance_ratio;
}