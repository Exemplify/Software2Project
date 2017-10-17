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
	DataMapper(std::string gameobject_datafile, std::string gamestate_datafile);
	/**
	 * @brief Updates the database provided with information stored by the 
	 * @param database 
	 */
	virtual void UpdateGameTimeDatabase(std::shared_ptr<DatabaseInterface> database) override;
private:
	std::string GetIDFromString(const std::string& ID_Line);
	GameObjectData getObjectDataFromString(const std::string& DataLine);
	std::vector<std::string> SplitGameObjectDataString(const std::string& DataLine);
	void UpdateGameObjectDatabaseInfo(std::shared_ptr<DatabaseInterface> database);
	void UpdateGameStateDatabaseInfo(std::shared_ptr<DatabaseInterface> database);
	std::string _gameobject_datafile;
	std::string _gamestate_datafile;
};

#endif