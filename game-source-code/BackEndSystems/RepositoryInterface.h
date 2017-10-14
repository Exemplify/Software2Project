#ifndef REPO_INTER_H
#define REPO__INTER_H
#include "../FrontEndSystems/Scene.h"
#include <vector>
#include <memory>


class RepositioryInterface
{
public:
	virtual std::vector<std::shared_ptr<Scene>> getGameScenes() = 0;
//	virtual std::shared_ptr<GameObject> getPlayerProjectile() = 0;
//	virtual std::shared_ptr<GameObject> getEnemyProjectile() = 0;
//	virtual std::shared_ptr<GameObject> getRandomEnemyObject() = 0;
	virtual ~RepositioryInterface() = default;
};

#endif