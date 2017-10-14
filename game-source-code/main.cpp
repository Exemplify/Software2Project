#include "BackEndSystems/GameManager.h"
#include <memory>
#include <iostream>
#include "BackEndSystems/Repository.h"
#include "BackEndSystems/DataMapper.h"
#include "BackEndSystems/RunTimeDatabase.h"

int main()
{
	auto database = std::make_shared<RunTimeDatabase>();
	auto dataMapper =  std::make_shared<DataMapper>("game_data/gameobjectdata.txt", "game_data/gamestatedata.txt");
	auto repository = std::make_shared<Repository>(dataMapper, database);
	auto gameScenes = repository->getGameScenes();
	GameManager gm;
	gm.AddScene(gameScenes[0]);
	gm.AddScene(gameScenes[1]);
	gm.AddScene(gameScenes[2]);
	gm.AddScene(gameScenes[3]);
	gm.GameLoop();
	return EXIT_SUCCESS;
}



