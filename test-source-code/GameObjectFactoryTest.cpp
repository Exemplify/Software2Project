#include "../game-source-code/BackEndSystems/PlayerFactory.h"
#include "../game-source-code/BackEndSystems/PlayerProjectileFactory.h"
#include "../game-source-code/BackEndSystems/EnemyFactory.h"
#include "../game-source-code/BackEndSystems/EnemyControllerFactory.h"
#include "../game-source-code/BackEndSystems/EnemyProjectileFactory.h"
#include "../game-source-code/BackEndSystems/WinScreenBackgroundFactory.h"
#include "../game-source-code/BackEndSystems/LoseScreenBackgroundFactory.h"
#include "../game-source-code/BackEndSystems/GameScreenBackgroundFactory.h"
#include "../game-source-code/BackEndSystems/SplashScreenBackgroundFactory.h"
#include "../game-source-code/FrontEndSystems/GraphicObject.h"
#include "../game-source-code/Vector2D.h"
#include "doctest.h"

template <typename first, typename second>
struct TypePair
{
    typedef first  A;
    typedef second B;
};

typedef doctest::Types<
	TypePair<PlayerFactory, Player>,
	TypePair<EnemyFactory, Enemy>,
	TypePair<EnemyControllerFactory, EnemyController>,
	TypePair<EnemyProjectileFactory, Projectile>,
	TypePair<PlayerProjectileFactory, Projectile>,
	TypePair<WinScreenBackgroundFactory, SplashScreen>,
	TypePair<LoseScreenBackgroundFactory, SplashScreen>,
	TypePair<GameScreenBackgroundFactory, SplashScreen>,
	TypePair<SplashScreenBackgroundFactory, SplashScreen>
	> FactoryPairs;

TEST_CASE_TEMPLATE("Factories Return the correct object types", T, FactoryPairs)
{
	typedef typename T::A FactoryType;
	typedef typename T::B ObjectType;
	
	FactoryType factory;
	auto gameObject = factory.getGameObject();
	auto castedObject = std::dynamic_pointer_cast<ObjectType>(gameObject);
	REQUIRE(castedObject.get() != nullptr);
	
	switch(castedObject->getType())
	{
		case GameObjectType::player:
			SUBCASE("1.1 The player object has the correct graphic")
			{
				auto testGraphic = castedObject->getGraphicObject();
				CHECK_EQ(testGraphic.getTextureLocation(), "resources/playerSprite.png");
				CHECK_EQ(testGraphic.getGraphicName(), "player");
			}
			SUBCASE("1.2 The player Obejct has the correct starting position")
			{
				Vector2D correctStartPos{0,-400, VectorType::xy};
				CHECK_EQ(castedObject->getPosition(), correctStartPos);
			}
			SUBCASE("1.3 The player Object has the correct scale")
			{
				xyVector correctScale{0.25f,0.25f};
				CHECK_EQ(castedObject->getScale(), correctScale);
			}
			break;
			
		case GameObjectType::enemy:
			SUBCASE("2.1 The Enemy object has the correct graphic")
			{
				auto testGraphic = castedObject->getGraphicObject();
				CHECK_EQ(testGraphic.getTextureLocation(), "resources/AdamHabib.png");
				CHECK_EQ(testGraphic.getGraphicName(), "enemy");
			}
			SUBCASE("2.2 The Enemy object has the correct scale")
			{
				xyVector correctScale{0.25f,0.25f};
				CHECK_EQ(castedObject->getScale(), correctScale);
			}
			break;
			
		case GameObjectType::enemyBullet:
			SUBCASE("3.1 The Enemy Projectile object has the correct graphic")
			{
				auto testGraphic = castedObject->getGraphicObject();
				CHECK_EQ(testGraphic.getTextureLocation(), "resources/SouthAfricanPS.png");
				CHECK_EQ(testGraphic.getGraphicName(), "enemyBullet");
			}
			SUBCASE("3.2 The Enemy Projectile object has the correct scale")
			{
				xyVector correctScale{0.1, 0.1};
				CHECK_EQ(castedObject->getScale(), correctScale);
			}
			
		default:
			break;
	}
}

