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
// Display manager is in charge of running and managing the presentation of the game
// It runs in a seperate thread and draws the location of each graphic object based on their game position 
// and how it is relative to the screen position
/// can be converted into a singlton
class DisplayManager
{
public:
	/// Default constructor is redundant and can be removed
	DisplayManager() {}
	/// Constructor with a RenderWindow pointer is most likely going to be used to replace the 
	/// current implementation which uses the Initialise thread fucntion
	DisplayManager(RenderWindow* dispWindow);
	/// Intialise thread initialises the display thread and assigns the _dispwindow_ptr object 
	/// this should possibly be replaced with smart pointers in future
	void InitialiseThread(RenderWindow& dispWindow);
	/// destructor required for the standard pointer
	~DisplayManager() {_dispwindow_ptr = NULL;}
	
private:
	// pointer to the active render window
	RenderWindow* _dispwindow_ptr;
	// runs the display loop and is created in a seperate thread
	void renderThread();
	// Draws each sfml sprite object to the game window
	void Draw();
	// Draws the individual gameobject sprite, obtains the information from the gameobject itself 
	/// sprite information needs to be removed from the gameobject
	void DrawSpriteFromGameObject(shared_ptr<GameObject> GO);
	// Converts the gameobjects defined position into the screen space available
	Vector2f GameObjectScreenPosition(const GraphicObject& graphicObj);
	// On the first draw call of the game object this is called to set up the sfml texture and sprite information
	/// needs to set infomation up seperately to the gameobject
	/// gameobject does not need to know about sfml
	void InitialiseGraphicObject(SpriteInfo& initialSpriteInfo);
};


#endif 