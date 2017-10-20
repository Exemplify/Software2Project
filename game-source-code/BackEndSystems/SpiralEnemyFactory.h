#ifndef SPIRAL_ENEM_FAC_H
#define SPIRAL_ENEM_FAC_H
#include "EnemyFactory.h"

class SpiralEnemyFactory: public EnemyFactory
{
public:
	virtual std::shared_ptr<MovableInterface> getMovableType(const GameObjectData& data) override;
	virtual GameObjectData getEnemyData(std::shared_ptr<DatabaseInterface> database) override;
};

#endif