#ifndef VEC2D_CONV
#define VEC2D_CONV
#include <SFML/Graphics.hpp>
#include "../Vector2D.h"

/**
 * @class Vector2DConvert
 * @brief Converts a Vector2D object into an sfml Vector so that it can be used in the presentation layer
 */
class Vector2DConvert
{
public:
/**
 * @brief Converts a Vector2D (that represents a position in the game space) into a corresponding screen position 
 * @param position The position that needs to be converted into a position on the screen 
 * @return The corresponding screen position
 */
	static sf::Vector2f ConvertVector2DtoScreenPosition(Vector2D position);
private:
	static xyVector _screen_size; /**< The corresponding screen size for the window*/
};
#endif //VEC2D_CONV