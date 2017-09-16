#include "EventManager.h"
#include "Input.h"

EventManager::EventManager(RenderWindow* eventWindow):
_eventWindow(eventWindow)
{}
void EventManager::EventLoop(RenderWindow& eventWindow)
{
	Event event;
	while(eventWindow.pollEvent(event))
	{
		switch(event.type)
		{
		// window closed
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
void EventManager::KeyInput(const Event& event, bool state)
{
	switch(event.key.code)
	{
		case Keyboard::Key::Escape:
			Input::setButton(Keys::esc,true);
			break;
		case Keyboard::Key::Left:
			Input::setButton(Keys::left,true);
			break;
		case Keyboard::Key::Right:
			Input::setButton(Keys::right,true);
			break;
		default:
			break;
	}
}