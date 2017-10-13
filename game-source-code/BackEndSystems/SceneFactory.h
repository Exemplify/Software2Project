#ifndef SCENE_FAC_H
#define SCENE_FAC_H
#include "../FrontEndSystems/Scene.h"
#include "../FrontEndSystems/GameObject.h"
#include <vector>
#include <memory>
class SceneFactory
{
public:
	std::shared_ptr<Scene> getScene() const;
protected:
	virtual std::vector<std::shared_ptr<GameObject>> getGameObectList() const = 0;
};

#endif 