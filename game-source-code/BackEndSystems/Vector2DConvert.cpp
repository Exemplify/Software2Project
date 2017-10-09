#include "Vector2DConvert.h"

/**
 * @details Converts the game position which has a the origin at the centre of the screen into the screen position which has the
 * origin centred at the top left corner of the screen. This is done due to the nature of the game gyrus and how objects are
 * centered around the middle of the screen frequently.
 */
sf::Vector2f Vector2DConvert::ConvertVector2DtoScreenPosition(Vector2D<double> position)
{
	// Obtains the current xy screen position from the position Vector
	auto xyPosition = position.xypVector();
	auto x_pos = xyPosition[0];
	auto y_pos = xyPosition[1];
	// Converts the xy game position into the sfml screen position
	x_pos += (_screen_size.x/2);
	y_pos = -y_pos + (_screen_size.y/2);
	// returns the new Screen Position
	return sf::Vector2f(x_pos, y_pos);
}

xyVector Vector2DConvert::_screen_size{960,540};

