#ifndef BACK_FAC
#define BACK_FAC
#include "GameObjectFactory.h"
#include "../FrontEndSystems/SplashScreen.h"
#include <string>

/**
 * @class WinScreenBackgroundFactory
 * @brief WinScreenBackgroundFactory uses the template design pattern to create the various background objects used within the game
 */
class BackgroundFactory: public GameObjectFactory
{
public:
	BackgroundFactory(std::string backgroundID):
	_backgroundID{backgroundID}
	{}
	/**
	 * @brief Function call used to create a GameObject used as a background 
	 * @return Returns a GameObject with the specific graphic object for a specific background
	 */
	virtual std::shared_ptr<GameObject> getGameObject(const std::shared_ptr<DatabaseInterface>& database) final;
	virtual GameObjectData getObjectData(const std::shared_ptr<DatabaseInterface>& database) final;
	virtual ~BackgroundFactory() = default;
private:
	std::string _backgroundID;
};
#endif