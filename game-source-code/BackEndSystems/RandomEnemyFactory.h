#ifndef RAND_ENEM_FAC_H
#define RAND_ENEM_FAC_H
#include "GameObjectFactory.h"

/**
 * @class RandomEnemyFactory
 * @brief Used to construct a specific enemy at Random
 */
class RandomEnemyFactory : public GameObjectFactory
{
public: 
	/**
	 * @brief Constructs a Random Enemy by using the defined Enemy Factories
	 * @param database The DatabaseInterface that contains the information about the various GameObjects
	 * @return Returns The Random Enemy Constructed
	 */
	virtual std::shared_ptr<GameObject> 
						getGameObject(const std::shared_ptr<DatabaseInterface>& database) override;
GameObjectData getObjectData(const std::shared_ptr<DatabaseInterface>& database);

private:
	const unsigned int SPIRAL_PERCENTAGE_VALUE = 80; /**<The value that the generated number needs to be greater than to create a Spiral Enemy*/
	const unsigned int LINEAR_PERCENTAGE_VALUE = 30; /**<The value that the generated number needs to be greater than to create a Linear Enemy*/
	const unsigned int PARABOLIC_PERCENTAGE_VALUE = 0; /**<The value that the generated number needs to be greater than to create a Parabolic Enemy*/
	const unsigned int MAX_PERCENTAGE = 100; /**<The maximum value that can be generated*/
	/**
	 * @brief Creates an EnemyFactory at Random 
	 * @return Returns the constructed EnemyFactory
	 */
	std::shared_ptr<GameObjectFactory> getRandomFactory();
};

#endif 