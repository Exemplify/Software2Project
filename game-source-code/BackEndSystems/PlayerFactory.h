#ifndef PLAY_FAC_H
#define PLAY_FAC_H
#include "PhysicsObjectFactory.h"
#include <memory>
#include "../FrontEndSystems/Player.h"
#include "../FrontEndSystems/GameObject.h"

/**
 * @class PlayerFactory
 * @brief Derived class from the GameObjectFactory interface used to construct the player object
 */
class PlayerFactory: public PhysicsObjectFactory
{
public:

	/**
	* @brief Constructs the player object
	* @return Returns the construted player object
	*/
	virtual std::shared_ptr<GameObject> getGameObject(const std::shared_ptr<DatabaseInterface>& database) override;
		virtual GameObjectData getObjectData(const std::shared_ptr<DatabaseInterface>& database) override;
	virtual ~PlayerFactory() = default;
};

#endif