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
void DisplayManager::DrawSpriteFromGameObject(shared_ptr<GameObject> GO)
{
	//Checks if the current game object is active
	if(!GO->isActive())
		return;
	
	//Checks if the Gameobject forms part of the graphics child class
	auto graphicObject = GO->getGraphicObject();
	if(graphicObject)
	{
		auto currentObjectKey = graphicObject->getGraphicName();
		
		auto currentSpriteInfoHash = _spriteInfoTable.find(currentObjectKey);
		// Checks if the objects sprite information has already been defined
		if(currentSpriteInfoHash == _spriteInfoTable.end())
		{
			// defines the texture and sprite information for the newly created object
			InitialiseGraphicObject(*graphicObject, currentObjectKey);
		}
		// obtains the relative sfml screen position
		currentSpriteInfoHash = _spriteInfoTable.find(currentObjectKey);
		auto screenPosition = Vector2DConvert::ConvertVector2DtoScreenPosition(GO->getPosition());

		// sets the position and scale of the sprite accordingly
		auto currentSpriteData = currentSpriteInfoHash->second;
		currentSpriteData->sprite.setPosition(screenPosition);
		auto scale = GO->getScale();

		currentSpriteData->sprite.setScale(sf::Vector2f(scale.x, scale.y) );
		// draws the sprite to the scene
		_dispwindow_ptr->draw(currentSpriteData->sprite);
	}
}

// intialises the sprite and texture information if it has not been done previously
void DisplayManager::InitialiseGraphicObject(const GraphicObject& graphicObject, std::string gameObjectKey)
{
	
	auto newSpriteInfo = std::make_shared<SpriteInfo>();
	// declarations for the spriteInfo components to improve readability
	auto& texture = newSpriteInfo->texture;
	auto& texture_location = graphicObject.getTextureLocation();
	// if the texture does not exist then an exception is thrown
	if(!texture.loadFromFile(texture_location))
	{
		throw(FailedToLoadTexture());
	}
	else
	{
		// sets the current texture to the sprite
		newSpriteInfo->sprite.setTexture(newSpriteInfo->texture);
		// Obtains the bounds of the sprite so that the position can be set to
		// the sprites centre as this is more desirable for this project
		auto bounds = newSpriteInfo->sprite.getGlobalBounds();
		auto newOrigin = Vector2f((bounds.width/2),(bounds.height/2));
		
		// Defines the new origin, at the centre of the sprite
		newSpriteInfo->sprite.setOrigin(newOrigin);
		// Adds the Created spriteInfo to the unordered map
		_spriteInfoTable.insert({gameObjectKey, newSpriteInfo});
	}
}
