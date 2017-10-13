#ifndef GAME_SCENE_FAC_H
#define GAME_SCENE_FAC_H
#include "SceneFactory.h"
#include "../FrontEndSystems/GameObject.h"
#include <list>
#include <memory>
class GameSceneFactory: public SceneFactory
{
protected:
	virtual std::list<std::shared_ptr<GameObject>> getGameObectList() const override;
};

#endif 