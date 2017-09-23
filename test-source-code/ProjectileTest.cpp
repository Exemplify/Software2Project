#include <doctest.h>
#include <memory>
#include "../game-source-code/FrontEndSystems/Projectile.h"
#include "../game-source-code/FrontEndSystems/Scene.h"
#include <iostream>

TEST_CASE("Projectile moves correctly")
{
	auto testScene = std::make_shared<Scene>();
	auto testProj = std::make_shared<Projectile>();
	testScene->Instantiate(testProj);
	Vector2D<double> pos{0, 0, 0, VectorType::rtp};
	Vector2D<double> dir{0,1,0,VectorType::xyp};
	testProj->Initialise(pos,dir,1);
	testProj->Update();
	auto positionCheckVec = pos+dir;
	CHECK(doctest::Approx(testProj->getPosition().xypVector().at(0)) == positionCheckVec.xypVector().at(0));
	CHECK(doctest::Approx(testProj->getPosition().xypVector().at(1)) == positionCheckVec.xypVector().at(1));
	CHECK(doctest::Approx(testProj->getPosition().xypVector().at(2)) == positionCheckVec.xypVector().at(2));
}


TEST_CASE("Player Projectile is Destroyed when near the Origin")
{
	auto testScene = std::make_shared<Scene>();
	auto testProj = std::make_shared<Projectile>(GameObjectType::playerBullet);
	testScene->Instantiate(testProj);
	SUBCASE("Projectile is Destroyed when the x position is near the centre")
	{
		Vector2D<double> pos{PLAYER_PROJECTILE_DESTROY_REGION-1, 0, 0, VectorType::xyp};
		Vector2D<double> dir{0,0,0,VectorType::xyp};
		testProj->Initialise(pos,dir,1);
		testProj->Update();
		CHECK_EQ(testScene->getGameObjectList().size(), 0);
	}
	
	SUBCASE("Projectile is Destroyed when the y position is near the centre")
	{
		Vector2D<double> pos{0, PLAYER_PROJECTILE_DESTROY_REGION-1 , 0, VectorType::xyp};
		Vector2D<double> dir{0,0,0,VectorType::xyp};
		testProj->Initialise(pos,dir,1);
		testProj->Update();
		CHECK_EQ(testScene->getGameObjectList().size(), 0);
	}
}

TEST_CASE("Enemy Projectile is Destroyed when near the Origin")
{
	auto testScene = std::make_shared<Scene>();
	auto testProj = std::make_shared<Projectile>(GameObjectType::enemyBullet);
	testScene->Instantiate(testProj);
	SUBCASE("Projectile is Destroyed when the x position is outside the screen")
	{
		Vector2D<double> pos{PLAY_SCREEN_HALF_WIDTH+1, 0, 0, VectorType::xyp};
		Vector2D<double> dir{0,0,0,VectorType::xyp};
		testProj->Initialise(pos,dir,1);
		testProj->Update();
		CHECK_EQ(testScene->getGameObjectList().size(), 0);
	}
	
	SUBCASE("Projectile is Destroyed when the y position is outside the screen")
	{
		Vector2D<double> pos{0, PLAY_SCREEN_HALF_WIDTH+1 , 0, VectorType::xyp};
		Vector2D<double> dir{0,0,0,VectorType::xyp};
		testProj->Initialise(pos,dir,1);
		testProj->Update();
		CHECK_EQ(testScene->getGameObjectList().size(), 0);
	}
}
