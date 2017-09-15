#include "DisplayManager.h"
#include "GameManager.h"
#include <vector>
#include "../FrontEndSystems/GraphicObject.h"
#include <typeinfo>
#include <cmath>
#include <string>

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
}

void DisplayManager::InitialiseThread()
{
	std::thread dispthread(&DisplayManager::renderThread, this);
	dispthread.detach();
}

void DisplayManager::Draw()
{
	Texture texture;
	if (!texture.loadFromFile("resources/PlayerShield.png"))
	{
		// error...
	}
	else
	{
		Sprite sprite;
		sprite.setTexture(texture);
		auto bounds = sprite.getGlobalBounds();
		sprite.setOrigin(Vector2f((bounds.width/2),(bounds.height/2)));
		sprite.setScale(Vector2f(0.1f,0.1f));
		sprite.setPosition(Vector2f(1920,1080));
		_dispwindow_ptr->draw(sprite);
	}
	shared_ptr<Scene> activeScene = GameManager::activeScene;
	//Guard Clause
	if(activeScene == NULL)
		return;
	else
	{
		for(auto GO : activeScene->getGameObjectList())
		{
			DrawSpriteFromGameObject(*GO);
		}
	}
}

void DisplayManager::DrawSpriteFromGameObject(GameObject& GO)
{
	//Checks if the current game object is active
	if(!GO.isActive())
		return;
		
	//Checks if the Gameobject forms part of the graphics child class
	if(GraphicObject* graphicObj = dynamic_cast<GraphicObject*>(&GO))
	{
		shared_ptr<SpriteInfo> currentSpriteInfo = graphicObj->getSpriteInfo();
		if(!currentSpriteInfo->isdefined)
		{
			InitialiseGraphicObject(*currentSpriteInfo);
		}
		auto screenPosition = GameObjectScreenPosition(*graphicObj);
		currentSpriteInfo->sprite.setPosition(screenPosition);
		_dispwindow_ptr->draw(currentSpriteInfo->sprite);
	}
}

Vector2f DisplayManager::GameObjectScreenPosition(const GraphicObject& graphicObj)
{
	Vector2f screenPosition;
	auto gameVector = graphicObj.getPosition();
	auto gamePosition = gameVector.xypVector();
	
	auto x_pos = round(gamePosition[0]);
	auto y_pos = round(gamePosition[1]);
	
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
