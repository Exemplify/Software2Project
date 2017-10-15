#ifndef REPO_INTER_H
#define REPO_INTER_H
#include "../FrontEndSystems/Scene.h"
#include "../FrontEndSystems/GameObject.h"
#include "../Vector2D.h"
#include <string>
#include <vector>
#include <memory>


class RepositioryInterface
{
public:
	virtual std::vector<std::shared_ptr<Scene>> getGameScenes() const = 0;
	virtual std::shared_ptr<GameObject> getGameObjectbyType(GameObjectType objtype) const = 0;
	virtual std::vector<unsigned int> getGameScreenSize() const = 0;
	virtual std::string getGameName() const = 0;
	virtual ~RepositioryInterface() = default;
};

#endif