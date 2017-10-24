#ifndef EVENT_MAN_H
#define EVENT_MAN_H

#include <SFML/Graphics.hpp>
#include <memory>

using namespace sf;
/** 
 * @brief Event Manager has the responsibility of controlling and running the event loop.
 * @details Is used to detect when specific events are triggered, it runs inside of the main thread 
 * as per the recommendation of sfml
 */ 
class EventManager
{
public:
	/**
	 * @brief The Event loop determines when an sfml event has been triggered, is used to detect when user input is detected 
	 * @param eventWindow The referecne to the RenderWindow used by the GameLoop
	 */
	void EventLoop(RenderWindow& eventWindow);
private:
	/**
	 * @brief Asssigns the state to the input class for whether a key has been pressed or released
	 * @param event The Event that was triggered 
	 * @param state the state as to whether the key should be set released or pressed
	 */
	void KeyInput(const Event& event, bool state);
};



#endif