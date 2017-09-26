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
// should the above not come directly from the GameManager which has a struct directly containing this info?
/// Yes that would be better however i wasnt too concerned with this at the moment as i felt it belongs in the database 
/// information class
class FailedToLoadTexture{};
// should this not rather be located in the header

DisplayManager::DisplayManager(RenderWindow* dispWindow):
_dispwindow_ptr(dispWindow)
{}
// can the RenderWindow pointer not rather be implemented with a smart unique pointer?
/// initially I used a smart pointer for this but it caused a crash in the game, it felt like the object went out of scope 
/// and deleted the information while this was still trying to access it 
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
// infinite loop issues, why does this not entre an infinite loop, or does it, and is it intended to?
/// _dispwindow_ptr->isOpen() ensures that the loop runs only while the window/game is running, so it is a conditional infinite 
/// loop that operates in a seperate thread
void DisplayManager::InitialiseThread(RenderWindow& dispWindow)
{
	_dispwindow_ptr = &dispWindow;
	std::thread dispthread(&DisplayManager::renderThread, this);
	dispthread.detach();
}
// so It does run an infinite loop through a separate thread? Cleaver...
/// See above
void DisplayManager::Draw()
{
	shared_ptr<Scene> activeScene = GameManager::activeScene;
	//Guard Clauses
	if(activeScene == NULL )
		return;
	else
	{
		std::lock_guard<std::mutex> lock(activeScene->_gameObj_list_mutex);
		auto displayObjects = activeScene->getGameObjectList();
        // can't the above be done in the for loop by const reference on displayObjects? i.e. for(const GraphicObject& Go :: displayObjects) , or similar?
		/// The mutex protects information accross threads, but you want it to only be active for as short a period as possible
		/// when the mutex goes out of scope the information is now available to other threads so that they can use it
		/// the function InitialiseGraphicObject alters information within the Game Object for the moment
		for(auto GO : displayObjects)
		{
			///Probably not necessary was implemented before the mutex
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
    // good use of dynamic casting GameObject into Graphic object
	if(graphicCast)
	{
		auto currentSpriteInfo = graphicCast->getSpriteInfo();
		if(!currentSpriteInfo->isdefined)
		{
			InitialiseGraphicObject(*currentSpriteInfo);
		}
        // what is the purpose of the above if statement?
        /// The above statement is to initialise the textures and sprites for any object that has not existed yet
		/// this will later be reduced to a single database and will hopefully not be necessary once implemented properly
		auto screenPosition = GameObjectScreenPosition(*graphicCast);
        // does this convert the vector position used for the game physics to the actual screen pixel postion?
		/// GameObjectScreenPosition converts the GameObjects position vector into the physical screen space
		currentSpriteInfo->sprite.setPosition(screenPosition);
        // currentSpriteInfo in this function scope points to the sprite info of the GameObject (now a GraphicObject) that is concerned?
		///Yes.
		currentSpriteInfo->sprite.setScale(currentSpriteInfo->scale);
        // What does the abov actually do?
		/// the above uses the SFML sprite function that changes the size of the current sprite object
        //how is the currentSpriteInfo not overwritten?
		/// the currentSpriteInfo does not get overwritten
		_dispwindow_ptr->draw(currentSpriteInfo->sprite);
        // given that the currentSpriteInfo seems to be overwritten, what exactly does draw function act on in terms of currentSpriteInfo?
		/// draw is a sfml function that tells the window to draw this sprite at its current positon and with scale on to the screen 
	}
}

// Converts the GameObjects functional game position to the actual screen position?
/// Yes.
Vector2f DisplayManager::GameObjectScreenPosition(const GraphicObject& graphicObj)
{
	Vector2f screenPosition;
	auto gameVector = graphicObj.getPosition();
	auto gamePosition = gameVector.xypVector();
    // can this rather not be done in one line or be more explicitly defind in the type declaration
    // i.e. It is not obvious that gameVector is of our own Vector2D type.. and thus auto declearation
    // hides the intuitive reason as to why this is necessary...
	/// Not entirely sure of the question but auto is definitely better for the compiler.
	
	auto x_pos = gamePosition[0];
	auto y_pos = gamePosition[1];
    // is a .at(index) not a better way of declaring the vector extraction here?
	/// Not sure will need to ask Levit which is better, but fundamentally it doesnt make much differnce there may
	/// be a time complexity difference 
	
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