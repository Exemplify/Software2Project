#include "doctest.h"
#include "../game-source-code/BackEndSystems/LinearEnemyFactory.h"
#include "../game-source-code/FrontEndSystems/Enemy.h"
#include "../game-source-code/BackEndSystems/EnemyControllerFactory.h"
#include "../game-source-code/BackEndSystems/PlayerFactory.h"
#include "../game-source-code/BackEndSystems/PlayerProjectileFactory.h"
#include "../game-source-code/BackEndSystems/EnemyProjectileFactory.h"
#include "../game-source-code/FrontEndSystems/Scene.h"
#include "../game-source-code/Vector2D.h"
#include "../game-source-code/BackEndSystems/GameManager.h"
#include <memory>
#include <iostream>
#include "../game-source-code/BackEndSystems/Repository.h"
#include "../game-source-code/BackEndSystems/DataMapper.h"
#include "../game-source-code/BackEndSystems/RunTimeDatabase.h"
#include "../game-source-code/BackEndSystems/Application.h"


TEST_CASE("Test that the Collisions for the various game objects work correctly")
{
	auto database = std::make_shared<RunTimeDatabase>();
	const auto dataMapper =  std::make_shared<DataMapper>("game_data/gameobjectdata.txt", "game_data/gamestatedata.txt");
	const auto repository = std::make_shared<Repository>(dataMapper, database);
	auto application = std::make_shared<Application>(repository);
	auto testScene = std::make_shared<Scene>();
	
	SUBCASE("Check that the Enemy object collides correctly")
	{
		LinearEnemyFactory enemFac;
		EnemyControllerFactory enemConFac;
		auto testEnemy = std::dynamic_pointer_cast<Enemy>( enemFac.getGameObject(database));
		testEnemy->AssignEnemyController(enemConFac.getGameObject(database));
		testScene->Instantiate(testEnemy);
		SUBCASE("Enemy collides with the player bullet correctly")
		{
			testEnemy->collisionAction(GameObjectType::playerBullet);
			CHECK(testScene->getGameObjectList().size() == 0);
		}
		SUBCASE("Enemy collides with the player object correctly")
		{
			testEnemy->collisionAction(GameObjectType::player);
			CHECK(testScene->getGameObjectList().size() == 0);
		}
	}
	SUBCASE("Player Projectile collides correctly")
	{
		PlayerProjectileFactory playerProjFac;
		auto testProj = std::dynamic_pointer_cast<Projectile>(playerProjFac.getGameObject(database));
		testScene->Instantiate(testProj);
		SUBCASE("Player Projectile collides with enemy projectile correctly")
		{
			testProj->collisionAction(GameObjectType::enemyBullet);
			CHECK(testScene->getGameObjectList().size() == 0);
		}
		SUBCASE("Player Projectile collides with enemy correctly")
		{
			testProj->collisionAction(GameObjectType::enemy);
			CHECK(testScene->getGameObjectList().size() == 0);
		}
	}
	SUBCASE("Enemy Projectile collides correctly")
	{
		EnemyProjectileFactory enemyProjFac;
		auto testProj = std::dynamic_pointer_cast<Projectile>(enemyProjFac.getGameObject(database));
		testScene->Instantiate(testProj);
		SUBCASE("Enemy Projectile collides with player projectile correctly")
		{
			testProj->collisionAction(GameObjectType::playerBullet);
			CHECK(testScene->getGameObjectList().size() == 0);
		}
		SUBCASE("Enemy Projectile collides with player correctly")
		{
			testProj->collisionAction(GameObjectType::player);
			CHECK(testScene->getGameObjectList().size() == 0);
		}
	}
	
	SUBCASE("Check that the player collisions occur correctly")
	{
		Application::LoadScene(0);
		PlayerFactory playerfac;
		auto testPlayer = std::dynamic_pointer_cast<Player>(playerfac.getGameObject(database));
		testScene->Instantiate(testPlayer);
		SUBCASE("Player Collides with the enemy projectile correctly")
		{
			testPlayer->collisionAction(GameObjectType::enemyBullet);
			CHECK(Application::currentSceneIndex() == 3);
		}
		
		SUBCASE("Player Collides with the enemy correctly")
		{
			testPlayer->collisionAction(GameObjectType::enemy);
			CHECK(Application::currentSceneIndex() == 3);
		}
	}
}