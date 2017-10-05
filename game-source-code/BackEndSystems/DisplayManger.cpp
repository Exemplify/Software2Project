#include "DisplayManager.h"
#include "GameManager.h"
#include "../FrontEndSystems/GraphicObject.h"
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
	// ensures that the _dispwindow_ptr is Null when the loop closes
	_dispwindow_ptr = NULL;
}

// Initialises the display thread 
void DisplayManager::InitialiseThread()
{
	std::thread dispthread(&DisplayManager::renderThread, this);
	dispthread.detach();
}
// Draws the sprites to the window 
void DisplayManager::Draw()
{
	shared_ptr<Scene> activeScene = GameManager::activeScene;
	//Guard Clauses to make sure there is a scene available before trying to access it
	if(activeScene == NULL )
		return;
	else
	{
		// mutex is used to ensure that the _gameobject list is not being used by a current thread
		std::lock_guard<std::mutex> lock(activeScene->_gameObject_list_mutex);
		auto displayObjects = activeScene->getGameObjectList();
		for(auto GO : displayObjects)
		{
			// additional check to ensure that the gameobejct has not been deleted in a seperate thread
			if(GO != NULL)
				DrawSpriteFromGameObject(GO); 
		}
	}
}
// Draws each sprite that is stored inside the gameobject
/// needs to be changed to use a hashtable
void DisplayManager::DrawSpriteFromGameObject(shared_ptr<GameObject> GO)
{
	//Checks if the current game object is active
	if(!GO->isActive())
		return;
		
	//Checks if the Gameobject forms part of the graphics child class
	auto graphicCast = std::dynamic_pointer_cast<GraphicObject>(GO);
	if(graphicCast)
	{
		// Access the sprite information from the current gameObject 
		auto currentSpriteInfo = graphicCast->getSpriteInfo();
		// Checks if the objects sprite information has already been defined
		if(!currentSpriteInfo->isdefined)
		{
			// defines the texture and sprite information for the newly created object
			InitialiseGraphicObject(*currentSpriteInfo);
		}
		// obtains the relative sfml screen position
		auto screenPosition = GameObjectScreenPosition(*graphicCast);
		// sets the position and scale of the sprite accordingly
		currentSpriteInfo->sprite.setPosition(screenPosition);
		currentSpriteInfo->sprite.setScale(currentSpriteInfo->scale);
		// draws the sprite to the scene
		_dispwindow_ptr->draw(currentSpriteInfo->sprite);
	}
}

// Converts Game Position to the sfml Screen Position
Vector2f DisplayManager::GameObjectScreenPosition(const GraphicObject& graphicObj)
{
	// Obtains the current xy screen position from the gameobject
	Vector2f screenPosition;
	auto gameVector = graphicObj.getPosition();
	auto gamePosition = gameVector.xypVector();
	
	auto x_pos = gamePosition[0];
	auto y_pos = gamePosition[1];
	// Converts the xy game position into the sfml screen position
	screenPosition.x = x_pos + HALF_SCREEN_WIDTH;
	screenPosition.y = -y_pos + HALF_SCREEN_HEIGHT;
	
	return screenPosition;
}
// intialises the sprite and texture information if it has not been done previously
void DisplayManager::InitialiseGraphicObject(SpriteInfo& initialSpriteInfo)
{
	initialSpriteInfo.isdefined = true;
	
	// declarations for the spriteInfo components to improve readability
	/// redeclare as auto&
	Texture& curr_texture = initialSpriteInfo.texture;
	string& texture_location = initialSpriteInfo.textureLocation;
	Sprite& sprite = initialSpriteInfo.sprite;
	// if the resourse does not exist then an exception is thrown
	if(!curr_texture.loadFromFile(texture_location))
	{
		throw(FailedToLoadTexture());
	}
	else
	{
		// sets the current texture to the sprite
		sprite.setTexture(curr_texture);
		
		// Obtains the bounds of the sprite so that the position can be set to
		// the sprites centre as this is more desirable for this project
		auto bounds = sprite.getGlobalBounds();
		
		// Defines the new origin, at the centre of the sprite
		auto newOrigin = Vector2f((bounds.width/2),(bounds.height/2));
		sprite.setOrigin(newOrigin);
	}
}
