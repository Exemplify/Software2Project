#ifndef WIN_SCENE_FAC_H
#define WIN_SCENE_FAC_H
#include "MenuSceneFactory.h"
#include "GameObjectFactory.h"
#include "../FrontEndSystems/GameObject.h"
#include "WinScreenBackgroundFactory.h"
#include <list>
#include <memory>


class WinSceneFactory: public MenuSceneFactory
{
protected:
	virtual std::shared_ptr<BackgroundFactory> getFactory() const override
	{
		return std::make_shared<WinScreenBackgroundFactory>();
	}
};

#endif 