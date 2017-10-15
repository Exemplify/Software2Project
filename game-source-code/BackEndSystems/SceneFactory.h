#ifndef SCENE_FAC_H
#define SCENE_FAC_H
#include "../FrontEndSystems/Scene.h"
#include "../FrontEndSystems/GameObject.h"
#include "DatabaseInterface.h"
#include <list>
#include <memory>
class SceneFactory
{
public:
	std::shared_ptr<Scene> getScene(std::shared_ptr<DatabaseInterface> database) const;
protected:
	virtual std::list<std::shared_ptr<GameObject>> getGameObectList(std::shared_ptr<DatabaseInterface> database) const = 0;
};

#endif 