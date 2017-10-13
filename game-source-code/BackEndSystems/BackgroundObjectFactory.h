#ifndef BACK_FAC
#define BACK_FAC
#include "GameObjectFactory.h"
#include "../FrontEndSystems/SplashScreen.h"

/**
 * @class WinScreenBackgroundFactory
 * @brief WinScreenBackgroundFactory uses the template design pattern to create the various background objects used within the game
 */
class BackgroundFactory: public GameObjectFactory
{
public:
	/**
	 * @brief Function call used to create a GameObject used as a background 
	 * @return Returns a GameObject with the specific graphic object for a specific background
	 */
	std::shared_ptr<GameObject> getGameObject() final;
	virtual ~BackgroundFactory() {}
protected:
	/**
	 * @brief virtual function used as part of the Template Design Pattern method to specify the specific graphic object created
	 * @return Returns the specific graphic object for the desired BackgroundFactory subclass
	 */
	virtual GraphicObject getGraphicObject() = 0;
	/**
	 * @brief virtual function used as part of the Template Design Pattern method to specify the specific object scale created
	 * @return Returns the specific object scale for the desired BackgroundFactory subclass
	 */
	virtual xyVector getScale() = 0;
	
};
#endif