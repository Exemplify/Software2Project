#include "DisplayManager.h"

DisplayManager::DisplayManager(sf::RenderWindow* dispWindow):
_dispwindow_ptr(dispWindow)
{}

// Function that runs in a different thread (Seperation of concerns)
void DisplayManager::renderThread()
{
	while(_dispwindow_ptr->isOpen())
	{
		_dispwindow_ptr->clear(sf::Color::Black);
		Draw();
		_dispwindow_ptr->display();
	}
}

void DisplayManager::InitialiseThread()
{
	std::thread dispthread(&DisplayManager::renderThread, this);
	dispthread.detach();
}
void DisplayManager::Draw()
{}
