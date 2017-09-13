#include "EventManager.h"

EventManager::EventManager(RenderWindow* eventWindow):
_eventWindow(eventWindow)
{}
void EventManager::EventLoop()
{
	Event event;
	while(_eventWindow->pollEvent(event))
	{
		switch(event.type)
		{
		// window closed
        case Event::Closed:
            _eventWindow->close();
            break;
		
		// we don't process other types of events
        default:
            break;
		}
	}
}