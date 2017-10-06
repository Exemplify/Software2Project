#ifndef DispMan_H
#define DispMan_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <thread>
#include <string>
#include <unordered_map>
#include "../FrontEndSystems/SpriteInfo.h"
#include "../FrontEndSystems/Scene.h"
#include "../FrontEndSystems/GameObject.h"
#include "../FrontEndSystems/GraphicObject.h"
/// using namespace needs to be removed
using namespace sf;
using std::shared_ptr;
// Display manager is in charge of running and managing the presentation of the game
// It runs in a seperate thread and draws the location of each graphic object based on their game position 
// to the game window. It contains an unordered map of each sprite and texture for each graphic object type
/// can be converted into a singleton
class DisplayManager
{
public:
	// constructs a DisplayManager Object that intitialises a seperate thread used for the presentation layer
	DisplayManager(RenderWindow& renderWindow);
	// destructor required for the standard pointer
	~DisplayManager() {_dispwindow_ptr = NULL;}
	
private:
	// pointer to the active render window, uses a standard pointer because a shared pointer causes the application to crash when closed 
	RenderWindow* _dispwindow_ptr;
	// Hashtable used to store the different sprites and texture elements
	std::unordered_map<std::string, std::shared_ptr<SpriteInfo>> _spriteInfoTable;
	// Intialises the display thread from the DisplayManager constructor
	void InitialiseThread();
	// runs the display loop and is created in a seperate thread
	void renderThread();
	// Draws each sfml sprite object to the game window
	void Draw();
	
	// Helper Functions //
	// Draws the individual gameobject sprite, obtains the information from the gameobject itself 
	/// sprite information needs to be removed from the gameobject
	void DrawSpriteFromGameObject(shared_ptr<GameObject> GO);
	// Converts the gameobjects defined position into the screen space available
	Vector2f GameObjectScreenPosition(const GraphicObject& graphicObj);
	// On the first draw call of the game object this is called to set up the sfml texture and sprite information
	/// needs to set infomation up seperately to the gameobject
	/// gameobject does not need to know about sfml
	void InitialiseGraphicObject(SpriteInfo& initialSpriteInfo, std::string gameObjectKey);
};


#endif 