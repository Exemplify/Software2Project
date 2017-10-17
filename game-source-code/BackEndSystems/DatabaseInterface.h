#ifndef DATA_BASE_INTER_H
#define DATA_BASE_INTER_H
#include "GameData.h"
#include "string"
#include <unordered_map>

/**
 * @class DatabaseInterface
 * @brief Defines the interface necessary for any Database object implementations used to store information about the various GameObjects and the game state.
 */
class DatabaseInterface
{
public:
	/**
	 * @brief Used to obtain the various data that relates to the different GameObjects used inside the game
	 * @param ID The speciic ID required to return the correct object data
	 * @return Returns the GameObjectData relating to the object defined by the ID
	 */
	virtual GameObjectData getGameObjectData(std::string ID)  = 0;
	/**
	 * @brief Gets the data about the current state of the game
	 * @return Returns the GameStateData which relates to the game, including the game screen size and name
	 */
	virtual GameStateData getGameStateData() = 0;
	/**
	 * @brief Sets the object data at the corresponding ID provided into the database
	 * @param ID The ID of the object that neeeds to be set within the database
	 * @param gameObjectData The GameObjectData stored 
	 */
	virtual void setGameObjectData(std::string ID, GameObjectData gameObjectData) = 0;
	/**
	 * @brief Sets the GameStateData inside of the database
	 * @param gameStateData The specific GameStateData stored within the database
	 */
	virtual void setGameStateData(GameStateData gameStateData) = 0;
	
	virtual ~DatabaseInterface() = default;
	
};
#endif