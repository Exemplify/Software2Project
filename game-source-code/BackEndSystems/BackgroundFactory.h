#ifndef BACK_FAC
#define BACK_FAC
#include "GameObjectFactory.h"
#include "../FrontEndSystems/SplashScreen.h"
#include <string>

/**
 * @class BackgroundFactory
 * @brief BackgroundFactory uses the template design pattern to create the various SplashScreen objects used within the game
 */
class BackgroundFactory: public GameObjectFactory
{
public:
	/**
	 * @brief Costructs a BackgroundFactory which creates the specific SplashScreen defined by the backgroundID provided
	 * @param backgroundID
	 */
	BackgroundFactory(std::string backgroundID = "splashScreen"):
	_backgroundID{backgroundID}
	{}
	/**
	 * @brief Function call used to create a GameObject used as a background 
	 * @param database The specific DatabaseInterface that contains the information about the GameObjects 
	 * @return Returns a GameObject with the specific graphic object for a specific background
	 */
	virtual std::shared_ptr<GameObject> getGameObject(const std::shared_ptr<DatabaseInterface>& database) final;
	/**
	 * @brief used to obtain the specific GameObjectData defined for the current factory
	 * @param database The specific DatabaseInterface that contains the information about the GameObjects 
	 * @return The GameObjectData required for the construction of the object
	 */
	virtual GameObjectData getObjectData(const std::shared_ptr<DatabaseInterface>& database) final;
	virtual ~BackgroundFactory() = default;
private:
	std::string _backgroundID; /**<The specific SplashScreen Object that is created*/
};
#endif