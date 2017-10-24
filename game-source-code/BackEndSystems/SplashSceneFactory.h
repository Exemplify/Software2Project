#ifndef SPLASH_SCENE_FAC_H
#define SPLASH_SCENE_FAC_H
#include "MenuSceneFactory.h"
#include "GameObjectFactory.h"
#include "../FrontEndSystems/GameObject.h"
#include "BackgroundFactory.h"
#include <list>
#include <memory>

/**
 * @class SplashSceneFactory
 * @brief Creates the Splash Screen Scene for the game
 */
class SplashSceneFactory: public MenuSceneFactory
{
protected:
	virtual std::shared_ptr<BackgroundFactory> getFactory() const override
	{
		return std::make_shared<BackgroundFactory>("splashScreen");
	}
};

#endif 