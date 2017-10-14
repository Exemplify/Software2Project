#ifndef REPO_H
#define REPO_H
#include "RepositoryInterface.h"
#include "DataMapperInterface.h"
#include "DatabaseInterface.h"
#include "SplashSceneFactory.h"
#include "WinSceneFactory.h"
#include "LoseSceneFactory.h"
#include "GameSceneFactory.h"

using std::shared_ptr;
using std::vector;

class Repository : public RepositioryInterface
{
public:
	Repository(shared_ptr<DataMapperInterface> dataMapper, shared_ptr<DatabaseInterface> runtime_database);
	virtual vector<shared_ptr<Scene>> getGameScenes() override;
private:
	shared_ptr<DataMapperInterface> _dataMapper;
	shared_ptr<DatabaseInterface> _runtime_database;
};


#endif