#ifndef GAME_SCENE_FAC_H
#define GAME_SCENE_FAC_H
#include "SceneFactory.h"
#include "../FrontEndSystems/GameObject.h"
#include <list>
#include <memory>
/**
 * @class GameSceneFactory
 * @brief Constructs the Scene that is used for the main game 
 */
class GameSceneFactory: public SceneFactory
{
protected:
	virtual std::list<std::shared_ptr<GameObject>> getGameObectList(std::shared_ptr<DatabaseInterface> database) const override;
};

#endif 