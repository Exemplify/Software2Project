#ifndef MENU_SCENE_FAC
#define MENU_SCENE_FAC
#include "SceneFactory.h"
#include "BackgroundObjectFactory.h"
#include "../FrontEndSystems/GameObject.h"
#include <list>
#include <memory>

class MenuSceneFactory: public SceneFactory
{
protected:
	std::list<std::shared_ptr<GameObject>> getGameObectList() const final;
	virtual std::shared_ptr<BackgroundFactory> getFactory() const = 0;
};

#endif