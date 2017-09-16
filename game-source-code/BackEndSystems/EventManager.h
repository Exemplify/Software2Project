#ifndef EVENT_MAN_H
#define EVENT_MAN_H

#include <SFML/Graphics.hpp>
#include <memory>

using namespace sf;

class EventManager
{
public:
	EventManager(){}
	EventManager(RenderWindow* eventWindow);
	void EventLoop(RenderWindow& eventWindow);
private:
	Event _currentEvent;
	std::shared_ptr<RenderWindow> _eventWindow;
};



#endif