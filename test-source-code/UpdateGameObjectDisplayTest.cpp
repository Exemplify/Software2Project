#include "doctest.h"
#include "../game-source-code/BackEndSystems/UpdateGameObjectDisplay.h"
#include "../game-source-code/FrontEndSystems/GameObject.h"
#include "../game-source-code/FrontEndSystems/GraphicObject.h"
#include <memory>

TEST_CASE("1.0 The Sprite graphic is updated correctly according to the GameObject provided")
{
	UpdateGameObjectDisplay updateObject;
	SUBCASE("1.1 Exception thrown when a graphic doesnt exist")
	{
		GraphicObject falseGraphic("FakeGraphic.jpeg", "FakeGraphic");
		auto testGameObject = std::make_shared<GameObject>(falseGraphic);
		REQUIRE_THROWS_AS(updateObject.DetermineGameObjectChanges(testGameObject), FailedToLoadTexture);
	}
	
	SUBCASE("1.2 The position of the sprite is updated correctly")
	{
		Vector2D gamePosition;
		auto testGameObject = std::make_shared<GameObject>(gamePosition);
		auto testSprite = updateObject.DetermineGameObjectChanges(testGameObject);
		sf::Vector2f expectedPosition{960, 540};
		auto recievedVector = testSprite.getPosition();
		CHECK_EQ(recievedVector,expectedPosition);
	}
	SUBCASE("1.3 The scale of the Object is updated correctly")
	{
		xyVector objectScale{10,10};
		auto testGameObject = std::make_shared<GameObject>(objectScale);
		auto testSprite = updateObject.DetermineGameObjectChanges(testGameObject);
		auto recievedScale = testSprite.getScale();
		sf::Vector2f testScale{10,10};
		CHECK_EQ(recievedScale, testScale);
	}
}