#include "EnemyFactory.h"
#include "../FrontEndSystems/Enemy.h"

/**
 * @details Creates the required parameters for each object and passes them by value to ensure that the information is copied to the object
 * This is done so that the default object information is not changed.
 */
std::shared_ptr<GameObject> EnemyFactory::getGameObject()
{
	xyVector scale{0.25f,0.25f};
	GraphicObject enemyGraphic("resources/AdamHabib.png", "enemy");
	GraphicObject enemyBulletGraphic{"resources/SouthAfricanPS.png","enemyBullet"};
	double colliderSize = 30;
	auto enemyShootDelay = 3.0;
	auto enemy = std::make_shared<Enemy>(scale, enemyGraphic, enemyBulletGraphic, colliderSize, enemyShootDelay);
	return enemy;
	
}