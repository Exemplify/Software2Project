#include <doctest.h>
#include <memory>
#include "../game-source-code/FrontEndSystems/Projectile.h"
#include "../game-source-code/BackEndSystems/GameManager.h"

TEST_CASE("Projectiles")
{
	GameManager gm;
	auto testScene = std::make_shared<Scene>();
	gm.activeScene = testScene;
	auto testProj = std::make_shared<Projectile>();
	testScene->Instantiate(testProj);
	gm.AddScene(testScene);
	SUBCASE("Projectile Moves in the correctly")
	{
		Vector2D<double> pos{PROJECTILE_DESTROY_REGION, 0, 0, VectorType::rtp};
		Vector2D<double> dir{0,1,0,VectorType::xyp};
		testProj->Initialise(pos,dir,1);
		testProj->Update();
		auto positionCheckVec = pos+dir;
		CHECK(testProj->getPosition() == positionCheckVec);
	}

	SUBCASE("Projectile is Destroyed when in near Origin")
	{
		Vector2D<double> pos{PROJECTILE_DESTROY_REGION-5, 0, 0, VectorType::rtp};
		Vector2D<double> dir{0,1,0,VectorType::xyp};
		testProj->Initialise(pos,dir,1);
		testProj->Update();
		CHECK_EQ(testScene->getGameObjectList().size(), 0);
	}
}