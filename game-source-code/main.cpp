#include "BackEndSystems/GameManager.h"
#include <memory>
#include <iostream>
#include "BackEndSystems/Repository.h"
#include "BackEndSystems/DataMapper.h"
#include "BackEndSystems/RunTimeDatabase.h"
#include "BackEndSystems/Application.h"

int main()
{
	auto database = std::make_shared<RunTimeDatabase>();
	const auto dataMapper =  std::make_shared<DataMapper>("game_data/gameobjectdata.txt", "game_data/gamestatedata.txt");
	const auto repository = std::make_shared<Repository>(dataMapper, database);
	auto application = std::make_shared<Application>(repository);
	application->RunApplication(); 
	
	return EXIT_SUCCESS;
}



