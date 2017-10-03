#ifndef EVENT_MAN_H
#define EVENT_MAN_H

#include <SFML/Graphics.hpp>
#include <memory>

using namespace sf;
/* 
 * Event Manager has the responsibility of controlling and running the event loop 
 * this is used to detect when specific events are triggered, it runs inside of the main thread 
 * as per the recommendation of sfml
 */ 
 /// can be converted into a singleton
class EventManager
{
public:
	/// redundant constructors should be removed, only a default is necessary with the event loop function
	EventManager(){}
	EventManager(RenderWindow* eventWindow);
	// Event loop determines when an event has been triggered from within sfml
	void EventLoop(RenderWindow& eventWindow);
private:
	/// redundant shared pointer 
	std::shared_ptr<RenderWindow> _eventWindow;
	// Asssigns the state to the input class for whether a key has been pressed or released
	void KeyInput(const Event& event, bool state);
};



#endif