#ifndef MENU_SCENE_FAC
#define MENU_SCENE_FAC
#include "SceneFactory.h"
#include "BackgroundFactory.h"
#include "../FrontEndSystems/GameObject.h"
#include <list>
#include <memory>

/**
 * @class MenuSceneFactory
 * @brief Creates the various MenuScenes within the game
 */
class MenuSceneFactory: public SceneFactory
{
protected:
	virtual std::list<std::shared_ptr<GameObject>> getGameObectList(std::shared_ptr<DatabaseInterface> database) const final;
	/**
	 * @brief returns the appropriate Scene Background Factory for the specific Menu Scene
	 * @return A factory object that is used to create the menu SplashScreen Objects
	 */
	virtual std::shared_ptr<BackgroundFactory> getFactory() const = 0;
};

#endif