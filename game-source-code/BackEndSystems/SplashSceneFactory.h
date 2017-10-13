#ifndef SPLASH_SCENE_FAC_H
#define SPLASH_SCENE_FAC_H
#include "SceneFactory.h"
#include "../FrontEndSystems/GameObject.h"
#include <vector>
#include <memory>
class SplashSceneFactory: public SceneFactory
{
protected:
	virtual std::vector<std::shared_ptr<GameObject>> getGameObectList() const override;
};

#endif 