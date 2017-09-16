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

class Input
{
public:
	static void clear();
	static bool IsButtonPressed(Keys key);
	static void setButton(Keys key, bool state);
private:
	static std::vector<bool> _buttons;
};

#endif