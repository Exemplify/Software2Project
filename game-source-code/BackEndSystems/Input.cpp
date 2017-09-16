#include "Input.h"
#include <algorithm>
const int MAX_NUM_INPUTS = 4;

void Input::clear()
{
	std::replace(std::begin(_buttons), std::end(_buttons), true, false);
}

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
std::vector<bool> Input::_buttons(static_cast<int>(Keys::Count));
