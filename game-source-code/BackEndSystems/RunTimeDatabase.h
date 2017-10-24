#ifndef DATA_BASE_H
#define DATA_BASE_H
#include "DatabaseInterface.h"
#include "GameData.h"
#include <string>
#include <unordered_map>
/**
 * @class DataDoesntExistInDatabase
 * @brief Exception thrown if information is accessed that doesnt exist in the database 
 */
class DataDoesntExistInDatabase{};
/**
 * @class DataAlreadyExistsInDatabase
 * @brief Exception thrown if information that exists in the database is overwritten
 */
class DataAlreadyExistsInDatabase{};
/**
 * @class RunTimeDatabase
 * @brief This class is responsible for storing a hashtable containing the various information about the different gameobjects used in the game. 
 * It also stores the information regarding the game state and provides access functionality as defined by the DatabaseInterface Interface class
 */
class RunTimeDatabase: public DatabaseInterface
{
public:
	virtual GameObjectData getGameObjectData(std::string ID) override;
	virtual GameStateData getGameStateData() override;
	virtual void setGameStateData(GameStateData gameStateData) override;
	virtual void setGameObjectData(std::string ID, GameObjectData gameObjectData) override;
	virtual ~RunTimeDatabase() = default;
protected:
	std::unordered_map<std::string, GameObjectData> _gameObjectData; /**<Hash Table datastructure used to store the GameObject information in the form of GameObjectData*/
	GameStateData _gameStateData; /**<Variable that stores the information about the game state*/
};
#endif