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
#include "UpdateGameObjectDisplay.h"
/// using namespace needs to be removed
using namespace sf;
using std::shared_ptr;
/**
 * @class DisplayManager
 * @brief Display manager is in charge of running and managing the presentation layer. 
 * @details It creates a seperate thread which is used to run the display loop.
 * The drawGameObject class is used to draw each of the GameObject's currently being used by the window. 
 */
class DisplayManager
{
public:
	DisplayManager(RenderWindow& renderWindow);
	/**
	 * @brief used to intialises the display loop for the game
	 */
	void InitialiseThread();
	// destructor required for the standard pointer
	~DisplayManager() {_dispwindow_ptr = NULL;}
	
private:
	
	RenderWindow* _dispwindow_ptr; /**<A pointer to the corresponding RenderWindow that needs images displayed to it>*/
	UpdateGameObjectDisplay _updateGameObjectDisplay; /**<Composition object responsible for for displaying each GameObject and the its corresponding Sprite>*/

	/**
	 * @brief Runs the display loop and is created in a seperate thread
	 */ 
	void renderThread();
	/**
	 * @brief Draws each sfml sprite object to the game window
	 */  
	void Draw();
};





#endif 