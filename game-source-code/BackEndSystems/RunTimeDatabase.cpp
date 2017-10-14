
#include "RunTimeDatabase.h"

GameObjectData RunTimeDatabase::getGameObjectData(std::string ID) 
{
	auto tableIterator = _gameObjectData.find(ID);
	if(tableIterator == _gameObjectData.end())
		throw DataDoesntExistInDatabase();
	return tableIterator->second;
}
GameStateData RunTimeDatabase::getGameStateData()
{
	return _gameStateData;
}
void RunTimeDatabase::setGameObjectData(std::string ID, GameObjectData gameObjectData)
{
	auto tableIterator = _gameObjectData.find(ID);
	if(tableIterator == _gameObjectData.end())
	{ 
		_gameObjectData.insert({ID, gameObjectData});
	}
}
void RunTimeDatabase::setGameStateData(GameStateData gameStateData)
{
	_gameStateData = gameStateData;
}