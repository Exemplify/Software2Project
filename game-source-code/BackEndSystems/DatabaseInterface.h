#ifndef DATA_BASE_INTER_H
#define DATA_BASE_INTER_H
#include "GameData.h"
#include "string"
#include <unordered_map>

class DatabaseInterface
{
public:
	virtual GameObjectData getGameObjectData(std::string ID)  = 0;
	virtual GameStateData getGameStateData() = 0;
	virtual void setGameObjectData(std::string ID, GameObjectData gameObjectData) = 0;
	virtual void setGameStateData(GameStateData gameStateData) = 0;
	
	virtual ~DatabaseInterface() = default;
};
#endif