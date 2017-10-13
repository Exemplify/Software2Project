#ifndef PLAY_FAC_H
#define PLAY_FAC_H
#include "GameObjectFactory.h"
#include <memory>
#include "../FrontEndSystems/Player.h"
#include "../FrontEndSystems/GameObject.h"

/**
 * @class PlayerFactory
 * @brief Derived class from the GameObjectFactory interface used to construct the player object
 */
class PlayerFactory: public GameObjectFactory
{
public:
	PlayerFactory() {}
/**
 * @brief Constructs the player object
 * @return Returns the construted player object
 */
	virtual std::shared_ptr<GameObject> getGameObject() override;
	virtual ~PlayerFactory() {}

};

#endif