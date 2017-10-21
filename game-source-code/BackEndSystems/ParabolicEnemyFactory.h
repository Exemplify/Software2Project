#ifndef PARABOLIC_ENEM_FAC_H
#define PARABOLIC_ENEM_FAC_H
#include "EnemyFactory.h"

class ParabolicEnemyFactory : public EnemyFactory
{
public:
	virtual std::shared_ptr<MovableInterface> getMovableType(const GameObjectData& data) override;
	virtual GameObjectData getEnemyData(std::shared_ptr<DatabaseInterface> database) override;
	virtual Vector2D getStartingPosition(const GameObjectData& data) override;
private:
	double determineParabolicCoefficient();
};
#endif