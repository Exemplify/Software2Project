#include "trompeloeil.hpp"
#include "doctest.h"
#include "../game-source-code/BackEndSystems/DatabaseInterface.h"
#include "../game-source-code/BackEndSystems/GameData.h"
#include "../game-source-code/BackEndSystems/DatabaseInterface.h"
#include "../game-source-code/BackEndSystems/PlayerFactory.h"
#include "../game-source-code/BackEndSystems/PlayerProjectileFactory.h"
#include "../game-source-code/BackEndSystems/LinearEnemyFactory.h"
#include "../game-source-code/BackEndSystems/ParabolicEnemyFactory.h"
#include "../game-source-code/BackEndSystems/SpiralEnemyFactory.h"
#include "../game-source-code/BackEndSystems/EnemyProjectileFactory.h"
#include "../game-source-code/BackEndSystems/EnemyControllerFactory.h"
#include "../game-source-code/BackEndSystems/BackgroundFactory.h"
#include "../game-source-code/FrontEndSystems/Enemy.h"
#include "../game-source-code/FrontEndSystems/SplashScreen.h"
#include "../game-source-code/FrontEndSystems/EnemyController.h"
#include "../game-source-code/FrontEndSystems/EnemyProjectile.h"
#include "../game-source-code/FrontEndSystems/Player.h"
#include "../game-source-code/FrontEndSystems/PlayerProjectile.h"
#include "../game-source-code/FrontEndSystems/GraphicObject.h"
#include "../game-source-code/Vector2D.h"
#include <string>

extern template struct trompeloeil::reporter<trompeloeil::specialized>;
////////////////////////////////// Database mock object //////////////////////////////////////////

class MockDatabaseInterface: public DatabaseInterface
{
public:
	MAKE_MOCK0(getGameStateData, GameStateData(void), override);
	MAKE_MOCK1(getGameObjectData, GameObjectData(std::string), override);
	MAKE_MOCK1(setGameStateData, void(GameStateData), override);
	MAKE_MOCK2(setGameObjectData, void(std::string, GameObjectData), override);
};

/////////////////////////////////////////////////////////////////////////////////////////////////

template <typename first, typename second>
struct TypePair
{
    typedef first  A;
    typedef second B;
};

typedef doctest::Types<
	TypePair<PlayerFactory, Player>,
	TypePair<PlayerProjectileFactory, PlayerProjectile>,
	TypePair<LinearEnemyFactory, Enemy>,
	TypePair<SpiralEnemyFactory, Enemy>, 
	TypePair<ParabolicEnemyFactory, Enemy>, 
	TypePair<EnemyProjectileFactory, EnemyProjectile>,
	TypePair<EnemyControllerFactory, EnemyController>,
	TypePair<BackgroundFactory, SplashScreen>
	> FactoryPairs;


TEST_CASE_TEMPLATE("Factories Return the correct object types", T, FactoryPairs)
{
	
	auto MockDatabase_ptr = std::make_shared<MockDatabaseInterface>();
	typedef typename T::A FactoryType;
	typedef typename T::B ObjectType;
	std::string testString;
	FactoryType factory;
	GameObjectData mockData{1, 2, 3, 4, "5", "6", 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	REQUIRE_CALL(*MockDatabase_ptr, getGameObjectData(ANY(std::string))).RETURN(mockData).TIMES(AT_LEAST(1));
	auto gameObject = factory.getGameObject(MockDatabase_ptr);
	SUBCASE("1.1. The Object created is of the correct type")
	{
		auto castedObject = std::dynamic_pointer_cast<ObjectType>(gameObject);
		REQUIRE(castedObject.get() != nullptr);
	}
	SUBCASE("1.2. The GameObject has the correct position")
	{
		auto position = gameObject->getPosition();
		auto xyVec = position.getXYVector();
		CHECK_EQ(xyVec.x, mockData.PosX);
		CHECK_EQ(xyVec.y, mockData.PosY);
	}
	SUBCASE("1.3. The GameObject has the correct scale")
	{
		auto scale = gameObject->getScale();
		CHECK_EQ(scale.x, mockData.scaleX);
		CHECK_EQ(scale.y, mockData.scaleY);
	}
	SUBCASE("1.4. The GameObject has the correct graphic object")
	{
		auto graphic = gameObject->getGraphicObject();
		CHECK_EQ(graphic.getTextureLocation(), mockData.graphic_location);
		CHECK_EQ(graphic.getGraphicName(), mockData.graphic_name);
	}
}



