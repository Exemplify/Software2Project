#include "DisplayManager.h"
#include "GameManager.h"
#include "../FrontEndSystems/GraphicObject.h"
#include "../FrontEndSystems/SpriteInfo.h"
#include "Vector2DConvert.h"
#include <mutex>
#include <cmath>
#include <string>
#include <vector>

using std::string;
using graphicObj_ptr = shared_ptr<GraphicObject>;
/// the current screen size and width for the game, needs to be moved into a database
const int HALF_SCREEN_WIDTH = 960;
const int HALF_SCREEN_HEIGHT = 540;
// Exception thrown if a texture is not available
class FailedToLoadTexture{};

// Assigns dispWindow
DisplayManager::DisplayManager(RenderWindow& renderWindow):
_dispwindow_ptr{&renderWindow}
{
	InitialiseThread();
}

// Method used within the display thread
void DisplayManager::renderThread()
{
	// Checks if the display window is open
	while(_dispwindow_ptr->isOpen())
	{
		// clears the screen so that there is no image shadowing
		_dispwindow_ptr->clear(Color::Black);
		// draws the different sprites to the screen
		Draw();
		// displays all sprites that have been drawn to the scene
		_dispwindow_ptr->display();
	}
}

// Initialises the display thread 
void DisplayManager::InitialiseThread()
{
	std::thread dispthread(&DisplayManager::renderThread, this);
	dispthread.detach();
}
// Draws the sprite for each active gameobject that contains a graphic object component
void DisplayManager::Draw()
{
	shared_ptr<Scene> activeScene = GameManager::activeScene;
	// Guard Clause to make sure there is a scene available before trying to access it
	if(activeScene == NULL || GameManager::gameClosed())
		return;

	// mutex is used to ensure that the _gameobject list is not being used by a current thread
	std::lock_guard<std::mutex> lock(activeScene->_gameObject_list_mutex);
	auto displayObjects = activeScene->getGameObjectList();
	for(auto GO : displayObjects)
	{
		// additional check to ensure that the gameobejct has not been deleted in a seperate thread
		if(GO != NULL || !GO->isActive())
		{
			auto sprite 
			_dispwindow_ptr->draw(sprite); 
		}
	}
}


