#include "../game-source-code/BackEndSystems/PlayerFactory.h"
#include "../game-source-code/FrontEndSystems/GraphicObject.h"

#include "doctest.h"

TEST_CASE("1.0 Test that the player is constructed correctly by the player factory")
{
	PlayerFactory playerFac;
	auto playerGameObject = playerFac.getGameObject();
	auto playerTest = std::dynamic_pointer_cast<Player>(playerGameObject);
	SUBCASE("1.1 Requires that the output is of type player")
	{
		REQUIRE(playerTest != nullptr)
	}

	SUBCASE("1.2 The player object has the correct graphic")
	{
		auto testGraphic = playerTest->getGraphicObject();
		CHECK_EQ(testGraphic.getTextureLocation, "resources/playerSprite.png");
		CHECK_EQ(testGraphic.getGraphicName(), "player")
	}
	SUBCASE("1.3 The player Obejct has the correct starting position")
	{
		Vector2D<double> correctStartPos{0,-400, 0};
		CHECK_EQ(playerTest->getPosition(), correctStartPos);
	}
	
}
