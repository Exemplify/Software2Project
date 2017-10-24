#ifndef SCREEN_BOUND_H
#define SCREEN_BOUND_H
#include "../Vector2D.h"
#include "../BackEndSystems/Application.h"


// boundary class is checks if a Vector2D position is inside or outside specific box that is 
// centered at the origin
/**
 * @class Boundary
 * @brief Boundary class used to represent a region of space centred around the origin, is able to determine if a specific point exists inside or outside of the bounds
 */
class Boundary
{
public: 
	/**
	* @brief Default Constructor
	* @details Creates the a boundary object with the current screen position as the default bounds
	*/
	Boundary();
	/**
	 * @brief Creates a boundary with the specified x and y bound
	 * @param xbound the distance of the boundary from the origin on the x axis
	 * @param ybound the distance of the boundary from the origin on the y axis
	 * @return 
	 */
	Boundary(double xbound, double ybound);

	/**
	 * @brief Determines if a specific Vector2D position is outside of the defined bounds
	 * @param objectPosition The specific position that is tested with the bounds
	 * @return Returns a bool whether the specified position is outside of the boundary
	 */
	bool OutOfBounds(const Vector2D& objectPosition) const;
	/**
	 * @brief Determines if a specific Vector2D position is inside of the defined bounds
	 * @param objectPosition The specific position that is tested with the bounds
	 * @return Returns a bool whether the specified position is inside of the boundary
	 */
	bool insideOfBounds(const Vector2D& objectPosition) const;
	
private:
	/**
	 * @brief Checks if the y position specified is within the y bounds
	 * @param yPos The y position that is tested
	 * @return Returns a bool whether the y position specified is greater than or less than the y coordinate of the boundary
	 */
	bool CheckyOutofBounds(double yPos) const;
	/**
	 * @brief Checks if the x position specified is within the x bounds
	 * @param xPos The x position that is tested
	 * @return Returns a bool whether the x position specified is greater than or less than the x coordinate of the boundary
	 */
	bool CheckxOutofBounds(double xPos) const;
	
	double _xBound; /**<The x value of the boundary specified*/
	double _yBound; /**<The y value of the boundary specified*/
};
#endif