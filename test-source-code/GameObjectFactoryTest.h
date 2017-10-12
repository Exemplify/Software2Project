#include "../game-source-code/BackEndSystems/PlayerFactory.h"
#include "../game-source-code/BackEndSystems/EnemyFactory.h"
#include "../game-source-code/FrontEndSystems/GraphicObject.h"
#include "../game-source-code/FrontEndSystems/Player.h"
#include "../game-source-code/FrontEndSystems/Enemy.h"
#include "../game-source-code/Vector2D.h"


#include "doctest.h"

TEST_CASE("1.0 Test that the player is constructed correctly by the player factory")
{
	PlayerFactory playerFac;
	auto playerGameObject = playerFac.getGameObject();
	auto playerTest = std::dynamic_pointer_cast<Player>(playerGameObject);
	SUBCASE("1.1 Requires that the output is of type player")
	{
		REQUIRE_FALSE(playerTest);
	}

	SUBCASE("1.2 The player object has the correct graphic")
	{
		auto testGraphic = playerTest->getGraphicObject();
		CHECK_EQ(testGraphic.getTextureLocation, "resources/playerSprite.png");
		CHECK_EQ(testGraphic.getGraphicName(), "player")
	}
	SUBCASE("1.3 The player Obejct has the correct starting position")
	{
		Vector2D correctStartPos{0,-400, 0};
		CHECK_EQ(playerTest->getPosition(), correctStartPos);
	}
	SUBCASE("1.4 The player Object has the correct scale")
	{
		xyVector correctScale{0.25f,0.25f};
		CHECK_EQ(playerTest->getScale(), correctScale);
	}
}

TEST_CASE("2.0 Test that the enemy is constructed correctly by the enemy factory")
{
	EnemyFactory enemyFactoryTest;
	auto enemyGameObject = enemyFactoryTest.getGameObject();
	auto enemyTest = std::dynamic_pointer_cast<Enemy>()
	
	SUBCASE("2.1 Requires the Output to be of type enemy")
	{
		REQUIRE_FALSE(enemyTest);
	}
	SUBCASE("2.2 The Enemy object has the correct graphic")
	{
		auto testGraphic = playerTest->getGraphicObject();
		CHECK_EQ(testGraphic.getTextureLocation, "resources/AdamHabib.png");
		CHECK_EQ(testGraphic.getGraphicName(), "enemy")
	}
	SUBCASE("2.2 The Enemy object has the correct scale")
	{
		xyVector correctScale{0.25f,0.25f};
		CHECK_EQ(enemyTest->getScale(), correctScale);
	}
}

TEST_CASE_TEMPLATE
