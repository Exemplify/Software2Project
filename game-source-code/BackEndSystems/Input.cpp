#include "Input.h"
#include <algorithm>


std::vector<bool> Input::_buttons(static_cast<int>(Keys::NumberOfKeys));

bool Input::IsButtonPressed(Keys key)
{
	auto index_bool = static_cast<int>(key);
	return _buttons.at(index_bool);
}
void Input::setButton(Keys key, bool state)
{
	auto index_bool = static_cast<int>(key);
	_buttons[index_bool] = state;
}

int Input::getAxis(Axis axis)
{
	if(axis == Axis::horizontal)
		return CheckButtonForAxis(Keys::left,Keys::right);
	else 
		return 0;
}
int Input::CheckButtonForAxis(Keys negativeKey, Keys positiveKey)
{
	if(IsButtonPressed(negativeKey))
		return -1;
	else if(IsButtonPressed(positiveKey))
		return 1;
	else
		return 0;
}