#include "Repository.h"


//	Repository(shared_ptr<DataMapperInterface> dataMapper, shared_ptr<DatabaseInterface> runtime_database);
//	virtual vector<shared_ptr<Scene>> getGameScenes() override;
//private:
//	shared_ptr<DataMapperInterface> _dataMapper;
//	shared_ptr<DatabaseInterface> _runtime_database;

Repository::Repository(shared_ptr<DataMapperInterface> dataMapper, 
						shared_ptr<DatabaseInterface> runtime_database):
_dataMapper{dataMapper},
_runtime_database{runtime_database}
{}

std::vector<shared_ptr<Scene>> Repository::getGameScenes()
{
	vector<shared_ptr<Scene>> gameScenes_vector;
	SplashSceneFactory splashSceneFactory;
	WinSceneFactory winSceneFactory;
	LoseSceneFactory loseSceneFactory;
	GameSceneFactory gameSceneFactory;
	
	gameScenes_vector.push_back(splashSceneFactory.getScene());
	gameScenes_vector.push_back(gameSceneFactory.getScene());
	gameScenes_vector.push_back(winSceneFactory.getScene());
	gameScenes_vector.push_back(loseSceneFactory.getScene());
	
	return gameScenes_vector;
}