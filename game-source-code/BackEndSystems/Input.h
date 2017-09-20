#ifndef INPUT_H
#define INPUT_H
#include <vector>


enum class Keys
{
	space,
	left,
	right,
	esc,
	Count
};

enum class Axis
{
	horizontal,
	vertical
};

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