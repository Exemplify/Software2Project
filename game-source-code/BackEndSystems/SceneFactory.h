#ifndef SCENE_FAC_H
#define SCENE_FAC_H
#include "../FrontEndSystems/Scene.h"
#include "../FrontEndSystems/GameObject.h"
#include <list>
#include <memory>
class SceneFactory
{
public:
	std::shared_ptr<Scene> getScene() const;
protected:
	virtual std::list<std::shared_ptr<GameObject>> getGameObectList() const = 0;
};

#endif 