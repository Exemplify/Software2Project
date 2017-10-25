#include "doctest.h"
#include "../game-source-code/FrontEndSystems/MovableInterface.h"
#include "../game-source-code/FrontEndSystems/LinearMove.h"
#include "../game-source-code/FrontEndSystems/SpiralMove.h"
#include "../game-source-code/FrontEndSystems/ParabolicMove.h"
#include "../game-source-code/FrontEndSystems/PlayerMove.h"
#include "../game-source-code/BackEndSystems/Input.h"
#include "../game-source-code/Vector2D.h"
 

typedef doctest::Types<LinearMove, PlayerMove, ParabolicMove, SpiralMove> the_types;

TEST_CASE_TEMPLATE_DEFINE("1 Test the various Scene Factories", T, test_id)
{
	// Is necessary to ensure that the PlayerMove is also tested
	Input::setButton(Keys::left, true); 
	
	SUBCASE("1.1 Check that the injected Vector2D has changed when the Move is called")
	{
		T moveComp{1};
		auto testPosition = Vector2D::right;
		moveComp.Move(testPosition);
		auto testXY = testPosition.getXYVector();
		auto positionChanged = testXY.x != 1 || testXY.y != 0;
		CHECK(positionChanged);
	}
}
TEST_CASE_TEMPLATE_INSTANTIATE(test_id, the_types);
