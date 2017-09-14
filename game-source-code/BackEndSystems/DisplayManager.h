#ifndef DispMan_H
#define DispMan_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <thread>
#include "FrontEndSystems/Scene.h"



using namespace sf;

class DisplayManager
{
public:
	DisplayManager(RenderWindow* dispWindow);
	void InitialiseThread();
private:
	std::shared_ptr<RenderWindow> _dispwindow_ptr;
	void renderThread();
	void Draw();
};

#endif 