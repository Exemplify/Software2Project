#include "RandomEnemyFactory.h"
#include "LinearEnemyFactory.h"
#include "SpiralEnemyFactory.h"
#include "ParabolicEnemyFactory.h"
#include <cmath>
#include <climits>
#include <ctime>

std::shared_ptr<GameObject> RandomEnemyFactory::getGameObject(std::shared_ptr<DatabaseInterface> database)
{

	auto randomFactory = getRandomFactory();
	auto enemyObject = randomFactory->getGameObject(database);
	return enemyObject;
}

std::shared_ptr<GameObjectFactory> RandomEnemyFactory::getRandomFactory()
{
	srand(time(NULL));
	auto randomMovementPercent = rand()%MAX_PERCENTAGE;
	std::shared_ptr<GameObjectFactory> factory_ptr;
	if(randomMovementPercent > SPIRAL_PERCENTAGE_VALUE)
	{
		factory_ptr = std::make_unique<SpiralEnemyFactory>();
	}
	else if(randomMovementPercent > LINEAR_PERCENTAGE_VALUE)
	{
		factory_ptr = std::make_shared<LinearEnemyFactory>();
	}
	else
	{
		factory_ptr = std::make_shared<ParabolicEnemyFactory>();
	}
	return factory_ptr;
}