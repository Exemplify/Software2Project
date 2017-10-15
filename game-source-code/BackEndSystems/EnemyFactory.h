#ifndef ENEM_FAC_H
#define ENEM_FAC_H
#include "GameObjectFactory.h"

/**
 * @class EnemyFactory
 * @brief Enemy Factory is responsible for the construction of any Enemy objects
 */
class EnemyFactory: public GameObjectFactory
{
public:
	/**
	 * @brief Function call used to create an Enemy Object 
	 * @return Returns an Enemy Object with the specific characteristics for this game
	 */
	virtual std::shared_ptr<GameObject> getGameObject(std::shared_ptr<DatabaseInterface> database) override; 
	virtual ~EnemyFactory() {}
};

#endif