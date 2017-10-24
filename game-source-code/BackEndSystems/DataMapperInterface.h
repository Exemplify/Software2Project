#ifndef DATA_MAPPER_INTER_H
#define DATA_MAPPER_INTER_H
#include <string>
#include <sstream>
#include <memory>
#include "GameData.h"
#include "DatabaseInterface.h"
/**
 * @class DataMapperInterface
 * @brief Is the interface used to update the specific DatabaseInterface required for the game.
 */
class DataMapperInterface
{
public:
	/**
	 * @brief Updates the runtime database with information obtained from an external source or file
	 * @param database The database that needs to be updated
	 */
	virtual void UpdateGameTimeDatabase(std::shared_ptr<DatabaseInterface> database) = 0;
	
	virtual ~DataMapperInterface() = default;
};
#endif