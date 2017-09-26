#include "EventManager.h"
#include "Input.h"

EventManager::EventManager(RenderWindow* eventWindow):
_eventWindow(eventWindow)
{}

void EventManager::EventLoop(RenderWindow& eventWindow)
{
	Event event;
    // What is the above line for | Event part of SFML lib, and typsets event to an Event
	/// This was taken directly from the sfml page for looping through events
	while(eventWindow.pollEvent(event))
	{
        // Events are logged and thus must be looped through as reccomended in the function declaration of .pollEvent(Event& event) of a RenderWindow
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
        // Switch checks the relevant events that are of concern
	}
}

void EventManager::KeyInput(const Event& event, bool state)
{
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
		default:
			break;
	}
}
// this specifically checks the case of a keypress event