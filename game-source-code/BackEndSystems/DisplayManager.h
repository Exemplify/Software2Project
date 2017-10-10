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
/**
 * @class DisplayManager
 * @author Timothy McBride
 * @date 09/10/2017
 * @brief Display manager is in charge of running and managing the presentation layer. 
 * @details It creates a seperate thread which is used to run the display loop. 
 * The drawGameObject class is used to draw each of the GameObject's currently being used by the window.
 */
class DisplayManager
{
	friend class DisplayManagerTester;
public:
	// constructs a DisplayManager Object that intitialises a seperate thread used for the presentation layer
	DisplayManager(RenderWindow& renderWindow);
	// destructor required for the standard pointer
	~DisplayManager() {_dispwindow_ptr = NULL;}
	
private:
	RenderWindow* _dispwindow_ptr;
	// Hashtable used to store the different sprites and texture elements

	// Intialises the display thread from the DisplayManager constructor
	
	void InitialiseThread();
	// runs the display loop and is created in a seperate thread
	void renderThread();
	// Draws each sfml sprite object to the game window
	void Draw();
	
	// Helper Functions //
	// Draws the individual gameobject sprite
	void DrawSpriteFromGameObject(shared_ptr<GameObject> GO);
	// On the first draw call of the game object this is called to set up the sfml texture and sprite information
	void InitialiseGraphicObject(const GraphicObject& graphicObject, std::string gameObjectKey);
};





#endif 