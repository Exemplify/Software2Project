#ifndef RAND_ENEM_FAC_H
#define RAND_ENEM_FAC_H
#include "GameObjectFactory.h"

class RandomEnemyFactory : public GameObjectFactory
{
public: 
	virtual std::shared_ptr<GameObject> 
						getGameObject(const std::shared_ptr<DatabaseInterface>& database) override;
GameObjectData getObjectData(const std::shared_ptr<DatabaseInterface>& database);

private:
	const unsigned int SPIRAL_PERCENTAGE_VALUE = 80;
	const unsigned int LINEAR_PERCENTAGE_VALUE = 30;
	const unsigned int PARABOLIC_PERCENTAGE_VALUE = 0;
	const unsigned int MAX_PERCENTAGE = 100;
	
	std::shared_ptr<GameObjectFactory> getRandomFactory();
};

#endif 