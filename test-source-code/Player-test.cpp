#include "doctest.h"
#include "../game-source-code/FrontEndSystems/Player.h"
#include "../game-source-code/BackEndSystems/Input.h"
#include "../game-source-code/FrontEndSystems/Scene.h"
#include "../game-source-code/Vector2D.h"
#include <memory>

//TEST_CASE("1. Player Initialised correctly")
//{
//	
//}
//
//TEST_CASE("2. Player Moves correctly")
//{
//	const int moveSpeed = 1;
//	const int playerHealth = 1;
//	Character playerCharacter(playerHealth, moveSpeed);
//	Vector2D PlayerStartPosition{1,0, VectorType::rt};
//	Player testPlayer{PlayerStartPosition, playerCharacter};
//	
//	SUBCASE("2.1 Player moves left when left input is true" )
//	{
//		Input::setButton(Keys::left, true);
//		testPlayer.Update();
//		Vector2D expectedVec{1,-1, VectorType::rt};
//		auto expectedVector = expectedVec.getRTVector();
//		auto testRT = testPlayer.getPosition().getRTVector();
//		CHECK(doctest::Approx(testRT.r) == expectedVector.r);
//		CHECK(doctest::Approx(testRT.t) == expectedVector.t);
//	}
//	SUBCASE("2.2 Player Moves right when right input is true")
//	{
//		Input::setButton(Keys::left, false);
//		Input::setButton(Keys::right, false);
//		testPlayer.Update();
//		// player has moved left previously and now moves back to the 0th angle
//		Vector2D expectedVec{1,0, VectorType::rt};
//		auto expectedVector = expectedVec.getRTVector();
//		auto testRT = testPlayer.getPosition().getRTVector();
//		CHECK(doctest::Approx(testRT.r) == expectedVector.r);
//		CHECK(doctest::Approx(testRT.t) == expectedVector.t);
//	}
//	
//}
//
//TEST_CASE("3.1 Player Shoots Correctly")
//{
//	const int moveSpeed = 1;
//	const int playerHealth = 1;
//	Character playerCharacter(playerHealth, moveSpeed);
//	Vector2D PlayerStartPosition{1,0, VectorType::rt};
//	auto testPlayer = std::make_shared<Player>(PlayerStartPosition, playerCharacter);
//	auto testScene = std::make_shared<Scene>();
//	
//	testScene->Instantiate(testPlayer);
//	Input::setButton(Keys::space, true);
//	testPlayer->Update();
//	auto listSize = testScene->getGameObjectList().size();
//	CHECK_EQ(listSize, 2);
//
//}