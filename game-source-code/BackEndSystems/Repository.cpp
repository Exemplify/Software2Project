#include "Repository.h"


//	Repository(shared_ptr<DataMapperInterface> dataMapper, shared_ptr<DatabaseInterface> runtime_database);
//	virtual vector<shared_ptr<Scene>> getGameScenes() override;
//private:
//	shared_ptr<DataMapperInterface> _dataMapper;
//	shared_ptr<DatabaseInterface> _runtime_database;

Repository::Repository(std::shared_ptr<DataMapperInterface> dataMapper, 
						std::shared_ptr<DatabaseInterface> runtime_database):
_dataMapper{dataMapper},
_runtime_database{runtime_database}
{
	_dataMapper->UpdateGameTimeDatabase(_runtime_database);
}

std::vector<std::shared_ptr<Scene>> Repository::getGameScenes() const
{
	vector<shared_ptr<Scene>> gameScenes_vector;
	SplashSceneFactory splashSceneFactory;
	WinSceneFactory winSceneFactory;
	LoseSceneFactory loseSceneFactory;
	GameSceneFactory gameSceneFactory;
	
	gameScenes_vector.push_back(splashSceneFactory.getScene(_runtime_database));
	gameScenes_vector.push_back(gameSceneFactory.getScene(_runtime_database));
	gameScenes_vector.push_back(winSceneFactory.getScene(_runtime_database));
	gameScenes_vector.push_back(loseSceneFactory.getScene(_runtime_database));
	
	return gameScenes_vector;
}

std::shared_ptr<GameObject> Repository::getGameObjectbyType(GameObjectType objtype) const
{

	switch(objtype)
	{
		case GameObjectType::playerBullet:
		{
			PlayerProjectileFactory objectFactory;
			return objectFactory.getGameObject(_runtime_database);
			break;
		}
		case GameObjectType::enemyBullet:
		{
			EnemyProjectileFactory objectFactory;
			return objectFactory.getGameObject(_runtime_database);
			
		}
		case GameObjectType::enemy:
		{
			EnemyFactory objectFactory;
			return objectFactory.getGameObject(_runtime_database);
		}
		default:
		{
			throw GameObjectTypeConstructionNotDefined();
			break;
		}
	}
}

std::vector<unsigned int> Repository::getGameScreenSize() const
{
	auto gamestateData = _runtime_database->getGameStateData();
	return std::vector<unsigned int>{gamestateData.screen_size_x, gamestateData.screen_size_y };
}
std::string Repository::getGameName() const
{
	auto gamestateData = _runtime_database->getGameStateData();
	return gamestateData.gameName;
}
