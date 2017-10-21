#ifndef ENEM_FAC_H
#define ENEM_FAC_H
#include "GameObjectFactory.h"
#include "../Vector2D.h"
#include "../FrontEndSystems/MovableInterface.h"


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
	virtual std::shared_ptr<GameObject> getGameObject(std::shared_ptr<DatabaseInterface> database) final; 
	virtual Vector2D getStartingPosition(const GameObjectData& data); 
	virtual GameObjectData getEnemyData(std::shared_ptr<DatabaseInterface> database) = 0;
	virtual std::shared_ptr<MovableInterface> getMovableType(const GameObjectData& data) = 0;
	virtual ~EnemyFactory() = default;
};

#endif