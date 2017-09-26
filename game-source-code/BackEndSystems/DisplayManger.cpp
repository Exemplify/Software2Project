#include "DisplayManager.h"
#include "GameManager.h"
#include "../FrontEndSystems/GraphicObject.h"
#include <mutex>
#include <cmath>
#include <string>
#include <vector>

using std::string;
using graphicObj_ptr = shared_ptr<GraphicObject>;

const int HALF_SCREEN_WIDTH = 960;
const int HALF_SCREEN_HEIGHT = 540;
class FailedToLoadTexture{};

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
	_dispwindow_ptr = NULL;
}

void DisplayManager::InitialiseThread(RenderWindow& dispWindow)
{
	_dispwindow_ptr = &dispWindow;
	std::thread dispthread(&DisplayManager::renderThread, this);
	dispthread.detach();
}

void DisplayManager::Draw()
{
	shared_ptr<Scene> activeScene = GameManager::activeScene;
	//Guard Clauses
	//Short circuit or so ensures that scene is active befor checking for UpdateList
	if(activeScene == NULL )
		return;
	else
	{
		std::lock_guard<std::mutex> lock(activeScene->_gameObj_list_mutex);
		auto displayObjects = activeScene->getGameObjectList();
		for(auto GO : displayObjects)
		{
			if(GO != NULL)
				DrawSpriteFromGameObject(GO);
		}
	}
}

void DisplayManager::DrawSpriteFromGameObject(shared_ptr<GameObject> GO)
{
	//Checks if the current game object is active
	if(!GO->isActive())
		return;
		
	//Checks if the Gameobject forms part of the graphics child class
	auto graphicCast = std::dynamic_pointer_cast<GraphicObject>(GO);
	if(graphicCast)
	{
		auto currentSpriteInfo = graphicCast->getSpriteInfo();
		if(!currentSpriteInfo->isdefined)
		{
			InitialiseGraphicObject(*currentSpriteInfo);
		}
		auto screenPosition = GameObjectScreenPosition(*graphicCast);
		currentSpriteInfo->sprite.setPosition(screenPosition);
		auto objectScale = graphicCast->getScale().xypVector();
		currentSpriteInfo->sprite.setScale(Vector2f(objectScale.at(0), objectScale.at(1)));
		_dispwindow_ptr->draw(currentSpriteInfo->sprite);
		
	}
}

Vector2f DisplayManager::GameObjectScreenPosition(const GraphicObject& graphicObj)
{
	Vector2f screenPosition;
	auto gameVector = graphicObj.getPosition();
	auto gamePosition = gameVector.xypVector();
	
	auto x_pos = gamePosition[0];
	auto y_pos = gamePosition[1];
	
	screenPosition.x = x_pos + HALF_SCREEN_WIDTH;
	screenPosition.y = -y_pos + HALF_SCREEN_HEIGHT;
	
	return screenPosition;
}

void DisplayManager::InitialiseGraphicObject(SpriteInfo& initialSpriteInfo)
{
	initialSpriteInfo.isdefined = true;
	
	// declarations for the spriteInfo components to improve readability
	Texture& curr_texture = initialSpriteInfo.texture;
	string& texture_location = initialSpriteInfo.textureLocation;
	Sprite& sprite = initialSpriteInfo.sprite;
	
	if(!curr_texture.loadFromFile(texture_location))
	{
		throw(FailedToLoadTexture());
	}
	else
	{
		sprite.setTexture(curr_texture);
		
		// Obtains the bounds of the sprite so that the position can be set to
		// the sprites centre as this is more desirable for this project
		auto bounds = sprite.getGlobalBounds();
		
		// Defines the new origin, at the centre of the sprite
		auto newOrigin = Vector2f((bounds.width/2),(bounds.height/2));
		sprite.setOrigin(newOrigin);
	}
}
