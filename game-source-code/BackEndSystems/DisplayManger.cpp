#include "DisplayManager.h"

DisplayManager::DisplayManager(RenderWindow* dispWindow):
_dispwindow_ptr(dispWindow)
{}

// Method used within the display thread
void DisplayManager::renderThread()
{
	while(_dispwindow_ptr->isOpen())
	{
		_dispwindow_ptr->clear(Color::Black);
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
{
//	std::shared_ptr<Scene> activeScene =  GameManager::activeScene;
//	Guard Clause
//	if(activeScene == NULL)
//		return;
//		
//	for(auto GO : activeScene->getGameObjectList())
//	{
//		Checks if the Gameobject is active and has a graphic
//		if(GO->getHasGraphic && GO->getActive())
//		{
//			GO->getSprite()
//		}
//	}
}
