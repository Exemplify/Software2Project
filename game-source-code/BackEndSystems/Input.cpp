#include "Input.h"
#include <algorithm>


std::vector<bool> Input::_buttons(static_cast<int>(Keys::Count));

void Input::clear()
{
	std::replace(std::begin(_buttons), std::end(_buttons), true, false);
}
// sets all the concerned input states to fales

bool Input::IsButtonPressed(Keys key)
{
	auto index_bool = static_cast<int>(key);
	return _buttons.at(index_bool);
}
// returns the current state of a particular concern on buttons

void Input::setButton(Keys key, bool state)
{
	auto index_bool = static_cast<int>(key);
	_buttons[index_bool] = state;
    // possibly use the same syntax as above with .at(index)?
}
// allows for outside state control on the buttons. Agreably necessary.

// since there is an indivdual state check button why is the below functions necessary?
int Input::getAxis(Axis axis)
{
	if(axis == Axis::horizontal)
		return CheckButtonForAxis(Keys::left,Keys::right);
        // What's the point if you are going to check the keytype anyway with CheckButtonForAxis?
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
// Refering to above, what's the point if this state is checked anyway?