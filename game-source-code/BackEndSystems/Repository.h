#ifndef REPO_H
#define REPO_H
#include "RepositoryInterface.h"
#include "DataMapperInterface.h"
#include "DatabaseInterface.h"
#include "SplashSceneFactory.h"
#include "WinSceneFactory.h"
#include "LoseSceneFactory.h"
#include "GameSceneFactory.h"
#include "PlayerProjectileFactory.h"
#include "EnemyProjectileFactory.h"
#include "EnemyFactory.h"

class GameObjectTypeConstructionNotDefined{};


class Repository : public RepositioryInterface
{
public:
	Repository(std::shared_ptr<DataMapperInterface> dataMapper, std::shared_ptr<DatabaseInterface> runtime_database);
	virtual std::shared_ptr<GameObject> getGameObjectbyType(GameObjectType objtype) const override;
	virtual std::vector<std::shared_ptr<Scene>> getGameScenes() const override;
	virtual std::vector<unsigned int> getGameScreenSize() const override;
	virtual std::string getGameName() const override;
	
	virtual ~Repository() = default;
private:
	std::shared_ptr<DataMapperInterface> _dataMapper;
	std::shared_ptr<DatabaseInterface> _runtime_database;
};


#endif