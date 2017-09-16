#include "EventManager.h"

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
		// we don't process other types of events at the moment
        default:
            break;
		}
	}
}