#ifndef GAME_OBJ_FAC_H
#define GAME_OBJ_FAC_H

#include "../FrontEndSystems/GameObject.h"
#include "../FrontEndSystems/GraphicObject.h"
#include <memory>

/**
 * @class GameObjectFactory
 * @brief The interface class that is used to define the factory design pattern, it is used to create the various objects used within the game.
 */
class GameObjectFactory
{
public:
	virtual std::shared_ptr<GameObject> getGameObject() = 0;
};

#endif