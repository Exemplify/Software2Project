#ifndef INPUT_H
#define INPUT_H
#include <vector>

// Enumerator used to represent the keys uses a Count key to keep track of the current number of keys recorded
/// Should rename count to NumberOfKeys
enum class Keys
{
	space,
	left,
	right,
	esc,
	Count
};
// Axis is used to inherintly get direction instead of a key press simplifies the code required for directional movement
enum class Axis
{
	horizontal,
	vertical
};

class Input
{
public:
	// Used to set every bool to false
	static void clear();
	// returns a boolean for the specific key that is pressed 
	static bool IsButtonPressed(Keys key); 
	// returns an -1, 1, or 0 to identify the direction of movement by the axis
	static int getAxis(Axis axis);
	// sets the state of a button either true or false, would prefer if it were private but is required for testing
	static void setButton(Keys key, bool state);
private:
	// a vector of bools that are indexed by the enumerator
	static std::vector<bool> _buttons;
	// Uses the buttons to determine direction from button presses
	static int CheckButtonForAxis(Keys negativeKey, Keys positiveKey);
};

#endif