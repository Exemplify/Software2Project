#ifndef PLAYER_PROJ_FAC
#define PLAYER_PROJ_FAC
#include "GameObjectFactory.h"


class PlayerProjectileFactory: public GameObjectFactory
{
public:
	virtual std::shared_ptr<GameObject> getGameObject();
};


#endif
