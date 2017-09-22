#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source-code/FrontEndSystems/Scene.h"
#include "../game-source-code/FrontEndSystems/GameObject.h"
#include "../game-source-code/FrontEndSystems/GraphicObject.h"
#include "../game-source-code/FrontEndSystems/Player.h"
#include "../game-source-code/FrontEndSystems/Enemy.h"
#include "../game-source-code/FrontEndSystems/Projectile.h"
#include <memory>
#include <vector>
TEST_CASE("Scene Destroys Objects correctly")
{
	auto testScene = std::make_shared<Scene>();
	SUBCASE("Scene Destroys a GameObject")
	{
		auto testgameObj = std::make_shared<GameObject>();
		testScene->Instantiate(testgameObj);
		testScene->DestroyGameObject(testgameObj);
		CHECK_EQ(testScene->getGameObjectList().size(), 0);
	}
	SUBCASE("Scene Destroys a GraphicsObject")
	{
		auto testgraphObj = std::make_shared<GraphicObject>();
		testScene->Instantiate(testgraphObj);
		testScene->DestroyGameObject(testgraphObj);
		CHECK_EQ(testScene->getGameObjectList().size(), 0);
	}
	SUBCASE("Scene Destroys a Player Object")
	{
		auto testplayObj = std::make_shared<Player>();
		testScene->Instantiate(testplayObj);
		testScene->DestroyGameObject(testplayObj);
		CHECK_EQ(testScene->getGameObjectList().size(), 0);
	}
	SUBCASE("Scene Destroys an Enemy Object")
	{
		auto testenemObj = std::make_shared<Enemy>();
		testScene->Instantiate(testenemObj);
		testScene->DestroyGameObject(testenemObj);
		CHECK_EQ(testScene->getGameObjectList().size(), 0);
	}
	SUBCASE("Scene Destroys a Projectile Object")
	{
		auto testprojObj = std::make_shared<Projectile>();
		testScene->Instantiate(testprojObj);
		testScene->DestroyGameObject(testprojObj);
		CHECK_EQ(testScene->getGameObjectList().size(), 0);
	}
}


