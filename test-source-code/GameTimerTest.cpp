#include "doctest.h"
#include "../game-source-code/BackEndSystems/GameTime.h"

TEST_CASE("Default delta time is returned correctly")
{
	CHECK(GameTime::getDeltaTime() == 1);
	
	
}
