#include "EventManager.h"
#include "Input.h"


// performs the sfml event loop
void EventManager::EventLoop(RenderWindow& eventWindow)
{
	// loads all events that have been triggered
	Event event;
	while(eventWindow.pollEvent(event))
	{
		switch(event.type)
		{
		// window closed called by UI as well as the OS
        case Event::Closed:
            eventWindow.close();
            break;
		case Event::KeyPressed:
			KeyInput(event, true);
			break;
		case Event::KeyReleased:
			KeyInput(event, false);
		// Dont process other events
        default:
            break;
		}
	}
}
// Assigns whether an key has been pressed or released
void EventManager::KeyInput(const Event& event, bool state)
{
	// switch statement that checks for which keys are pressed, 
	// allows additional keys to be added easily
	switch(event.key.code)
	{
		case Keyboard::Key::Escape:
			Input::setButton(Keys::esc,state);
			break;
		case Keyboard::Key::Left:
			Input::setButton(Keys::left,state);
			break;
		case Keyboard::Key::Right:
			Input::setButton(Keys::right,state);
			break;
		case Keyboard::Key::Space:
			Input::setButton(Keys::space,state);
			break;
		case Keyboard::Key::Return:
			Input::setButton(Keys::enter,state);
		default:
			break;
	}
}