#ifndef DispMan_H
#define DispMan_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <thread>
#include <string>
#include "../FrontEndSystems/Scene.h"
#include "../FrontEndSystems/GameObject.h"
#include "../FrontEndSystems/GraphicObject.h"

using namespace sf;
using std::shared_ptr;

class DisplayManager
{
public:
	DisplayManager() {}
	DisplayManager(RenderWindow* dispWindow);
	void InitialiseThread(RenderWindow& dispWindow);
	~DisplayManager() {_dispwindow_ptr = NULL;}
	
private:
	RenderWindow* _dispwindow_ptr;
	void renderThread();
	void Draw();
	void DrawSpriteFromGameObject(shared_ptr<GameObject> GO);
	Vector2f GameObjectScreenPosition(const GraphicObject& graphicObj);
	void InitialiseGraphicObject(SpriteInfo& initialSpriteInfo);
};


#endif 