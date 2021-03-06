#ifndef ENEM_FAC_H
#define ENEM_FAC_H
#include "PhysicsObjectFactory.h"
#include "../Vector2D.h"
#include "../FrontEndSystems/MovableInterface.h"


/**
 * @class EnemyFactory
 * @brief Enemy Factory is the base class to the various types of enemies that are constructed
 */
class EnemyFactory: public PhysicsObjectFactory
{
public:
	/**
	 * @brief Function call used to create an Enemy Object 
	 * @return Returns an Enemy Object with the specific characteristics for this game
	 */
	virtual std::shared_ptr<GameObject> getGameObject(const std::shared_ptr<DatabaseInterface>& database) final;
	/**
	 * @brief Pure virtual function used to assign the various MovableInterfaces that the EnemyObjects use
	 * @param data The GameObjectData specific to the Enemy being constructed
	 * @return Returns the MovableInterface for the specific Enemy that is being constructed
	 */
	virtual std::shared_ptr<MovableInterface> getMovableType(const GameObjectData& data) = 0;
	
	virtual ~EnemyFactory() = default;
};

#endif