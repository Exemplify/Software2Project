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
	std::shared_ptr<RenderWindow> _eventWindow;
	void KeyInput(const Event& event, bool state);
};



#endif