#ifndef INPUT_H
#define INPUT_H
#include <vector>

/**
* @brief Enemurator class that represents the specific keys 
*/
enum class Keys
{
	space,
	left,
	right,
	esc,
	enter,
	NumberOfKeys
};
/**
* @brief Enumerator class that represents particular Axis 
*/
enum class Axis
{
	horizontal,
	vertical
};
/**
 * @class Input
 * @brief Responsible for supplying the FrontEndSystem with access to the input of the user by interfaceing with sfml
 */
class Input
{
public:

	/**
	 * @brief returns a boolean for the specific key that is pressed , returns true if the Key has been pressed
	 * @param key The specific key that needs to be checked if an input is detected
	 * @return 
	 */
	static bool IsButtonPressed(Keys key); 
	/**
	 * @brief Provides directional information inherintly, 
	 * @param axis The axis that the input occurs on 
	 * @return Returns a -1, 0, or 1 depending on the direction and axis that was pressed
	 */
	static int getAxis(Axis axis);
	/**
	 * @brief Sets the specific Key to the desired state of whether it is pressed or not
	 * @param key the specific key that is pressed or released 
	 * @param state the desired state 
	 */
	static void setButton(Keys key, bool state);
private:
	static std::vector<bool> _buttons; /**<a vector of bools that are indexed by the enumerator*/
	static int CheckButtonForAxis(Keys negativeKey, Keys positiveKey); /**<Uses the buttons to determine direction from button presses*/
};

#endif