#ifndef LIN_ENEM_FAC_H
#define LIN_ENEM_FAC_H
#include "EnemyFactory.h"
/**
 * @class LinearEnemyFactory
 * @brief Constructs an Enemy that moves in a straight line from the origin outwards
 */
class LinearEnemyFactory : public EnemyFactory
{
public:
	virtual std::shared_ptr<MovableInterface> getMovableType(const GameObjectData& data) override;
	virtual GameObjectData getObjectData(const std::shared_ptr<DatabaseInterface>& database) override;
};
#endif