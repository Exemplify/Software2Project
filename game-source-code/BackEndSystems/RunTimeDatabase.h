#ifndef DATA_BASE_H
#define DATA_BASE_H
#include "DatabaseInterface.h"
#include "GameData.h"
#include <string>
#include <unordered_map>

class DataDoesntExistInDatabase{};
class DataAlreadyExistsInDatabase{};
/**
 * @class GameInfoHashTable
 * @brief This class is responsible for storing a hashtable containing the various information about the different gameobjects used in the game. 
 * It also stores the information regarding the game state and provides access functionality as defined by the DatabaseInterface Interface class
 */
class RunTimeDatabase: public DatabaseInterface
{
public:
	GameObjectData getGameObjectData(std::string ID) override;
	GameStateData getGameStateData() override;
	void setGameStateData(GameStateData gameStateData) override;
	void setGameObjectData(std::string ID, GameObjectData gameObjectData) override;
	virtual ~RunTimeDatabase() = default;
protected:
	std::unordered_map<std::string, GameObjectData> _gameObjectData;
	GameStateData _gameStateData;
};
#endif