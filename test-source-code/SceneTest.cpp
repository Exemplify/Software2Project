#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source-code/FrontEndSystems/Scene.h"
#include "../game-source-code/FrontEndSystems/GameObject.h"
#include <memory>
TEST_CASE("Scene Destroys Objects correctly")
{
	auto testScene = std::make_shared<Scene>();
	SUBCASE("Scene Destroys a GameObject")
	{
		auto testgameObj = std::make_shared<GameObject>();
		testScene->Instantiate(testgameObj);
		CHECK_THROWS( testScene->DestroyGameObject(testgameObj.get()));
		CHECK_EQ(testScene->getGameObjectList().size(), 0);
	}

	
}