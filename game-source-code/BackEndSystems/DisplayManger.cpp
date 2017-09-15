#include "DisplayManager.h"
#include "GameManager.h"
#include <vector>
#include "../FrontEndSystems/GraphicObject.h"
#include <typeinfo>

using graphicObj_ptr = shared_ptr<GraphicObject>;


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
//	Texture texture;
//	if (!texture.loadFromFile("resources/PlayerShield.png"))
//	{
//		// error...
//	}
//	else
//	{
//		Sprite sprite;
//		sprite.setTexture(texture);
//		sprite.setScale(Vector2f(0.1f,0.1f));
//		_dispwindow_ptr->draw(sprite);
//
//	}
	shared_ptr<Scene> activeScene = GameManager::activeScene;
	//Guard Clause
	if(activeScene == NULL)
		return;
	else
	{
		for(auto GO : activeScene->getGameObjectList())
		{

		}
	}
}

void DisplayManager::DrawSpriteFromGameObject(GameObject& GO)
{
	//Checks if the current game object is active
	if(!GO.isActive())
		return;
	//Checks if the Gameobject is of to
	if(GraphicObject* graphicObj = dynamic_cast<GraphicObject*>(&GO))
	{
	}
}

