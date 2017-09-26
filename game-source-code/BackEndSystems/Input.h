#ifndef INPUT_H
#define INPUT_H
#include <vector>


enum class Keys
{
	space,
	left,
	right,
	esc,
	Count /// should be renamed NumberOfButtons
};

enum class Axis
{
	horizontal,
	vertical
};
// is this realy necessary given the above enum class
/// An Axis provides direction as well as state so is useful but maybe not neccesary for our purpose

class Input
{
public:
	static void clear();
	static bool IsButtonPressed(Keys key); 
	static int getAxis(Axis axis);
	static void setButton(Keys key, bool state);
private:
	static std::vector<bool> _buttons;
	static int CheckButtonForAxis(Keys negativeKey, Keys positiveKey);
};

#endif