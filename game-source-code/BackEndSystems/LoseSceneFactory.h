#ifndef LOSE_SCENE_FAC_H
#define LOSE_SCENE_FAC_H
#include "MenuSceneFactory.h"
#include "GameObjectFactory.h"
#include "../FrontEndSystems/GameObject.h"
#include "LoseScreenBackgroundFactory.h"
#include <list>
#include <memory>


class LoseSceneFactory: public MenuSceneFactory
{
protected:
	virtual std::shared_ptr<BackgroundFactory> getFactory() const override
	{
		return std::make_shared<LoseScreenBackgroundFactory>();
	}
};

#endif 