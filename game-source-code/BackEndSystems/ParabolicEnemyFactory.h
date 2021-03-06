#ifndef PARABOLIC_ENEM_FAC_H
#define PARABOLIC_ENEM_FAC_H
#include "EnemyFactory.h"

/**
 * @class ParabolicEnemyFactory
 * @brief Constructs an Enemy that is moves in a parabolic fashion from the edges of the screen to the centre of the screen
 */
class ParabolicEnemyFactory : public EnemyFactory
{
public:
	virtual std::shared_ptr<MovableInterface> getMovableType(const GameObjectData& data) override;
	virtual GameObjectData getObjectData(const std::shared_ptr<DatabaseInterface>& database) override;
private:
	double determineParabolicCoefficient();
};
#endif