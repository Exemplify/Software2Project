#ifndef DispMan_H
#define DispMan_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <thread>
#include <string>
#include "../FrontEndSystems/Scene.h"
#include "../FrontEndSystems/GameObject.h"
using namespace sf;
using std::shared_ptr;

class DisplayManager
{
public:
	DisplayManager(RenderWindow* dispWindow);
	void InitialiseThread();
private:
	std::shared_ptr<RenderWindow> _dispwindow_ptr;
	void renderThread();
	void Draw();
	void DrawSpriteFromGameObject(shared_ptr<GameObject> GO);
};


#endif 