#ifndef GAME_OBJ_FAC_H
#define GAME_OBJ_FAC_H

#include "../FrontEndSystems/GameObject.h"
#include "../FrontEndSystems/GraphicObject.h"
#include "DatabaseInterface.h"
#include <memory>

/**
 * @class GameObjectFactory
 * @brief The interface class that is used to define the factory design pattern, it is used to create the various objects used within the game.
 */
class GameObjectFactory
{
public:
	/**
	 * @brief virtual function used to create the desired class specified by the derived class
	 * @return Returns the constructed GameObject object
	 */
	virtual std::shared_ptr<GameObject> getGameObject(const std::shared_ptr<DatabaseInterface>& database);
	/**
	 * @brief used to obtain the specific GameObjectData defined for the current factory
	 * @param database The specific DatabaseInterface that contains the information about the GameObjects 
	 * @return The GameObjectData required for the construction of the object
	 */
	virtual GameObjectData getObjectData(const std::shared_ptr<DatabaseInterface>& database) = 0;
	virtual ~GameObjectFactory() {};
};

#endif