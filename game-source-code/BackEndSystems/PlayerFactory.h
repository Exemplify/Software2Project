#ifndef PLAY_FAC_H
#define PLAY_FAC_H
#include "GameObjectFactory.h"
#include <memory>
#include "../FrontEndSystems/Player.h"
#include "../FrontEndSystems/GameObject.h"

class PlayerFactory: public GameObjectFactory
{
public:
	virtual std::shared_ptr<GameObject> getGameObject() override;
};

#endif