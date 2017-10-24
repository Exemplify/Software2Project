#ifndef DATA_MAPPER_H
#define DATA_MAPPER_H
#include "DataMapperInterface.h"
#include "GameData.h"
#include "StringConversions.h"
#include "ReadFromFile.h"
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
// "game_data/gameobjectdata.txt"
/**
 * @class DataMapper
 * @brief DataMapper is responsible for mapping data recieved from the ReadFromFile object into usable datatypes and interfacing 
 * with the desired datatbase to update the information in it
 */
class DataMapper: public DataMapperInterface
{
public:
	/**
	 * @brief Constructs the DataMapper Object with two strings that represent the data files of the game 
	 * @param gameobject_datafile The datafile that contains the information about the various GameObjects of the game
	 * @param gamestate_datafile The datafile that contains the information about the state of the game, ie screen size 
	 */
	DataMapper(std::string gameobject_datafile, std::string gamestate_datafile);
	/**
	 * @brief Updates the the provided database with information stored in the datafiles provided
	 * @param database The DatabaseInterface that gets updated with the information
	 */
	virtual void UpdateGameTimeDatabase(std::shared_ptr<DatabaseInterface> database) override;
private:
	/**
	 * @brief Gets the ID of the object frm the string provided used as the key to store the information in the DatabaseInterface  
	 * @param ID_Line The line obtained from the text file that contains the ID - assumes the correct format is used within the text file
	 * @return returns the ID of the object obtained from the string
	 */
	std::string GetIDFromString(const std::string& ID_Line);
	/**
	 * @brief Converts and Constructs the GameObjectData from the string provided
	 * @param DataLine a string containing the various object information 
	 * @return Returns a GameObjectData constructed from the information provided by the string of data
	 */
	GameObjectData getObjectDataFromString(const std::string& DataLine);
	/**
	 * @brief Splits the string up into a vector of multiple strings seperated by spaces
	 * @param DataLine a string containing the various object information 
	 * @return Returns a vector of strings each representing a specific element of the GameObjectData
	 */
	std::vector<std::string> SplitGameObjectDataString(const std::string& DataLine);
	/**
	 * @brief Updates the GameObjectData of the database 
	 * @param database the DatabaseInterface that is updated
	 */
	void UpdateGameObjectDatabaseInfo(std::shared_ptr<DatabaseInterface> database);
	/**
	 * @brief Updates the GameState data of the database 
	 * @param database the DatabaseInterface that is updated
	 */
	void UpdateGameStateDatabaseInfo(std::shared_ptr<DatabaseInterface> database);
	
	std::string _gameobject_datafile; /**<The datafile that contains the information about the various GameObjects of the game*/
	std::string _gamestate_datafile; /**<The datafile that contains the information about the state of the game, ie screen size */
};

#endif