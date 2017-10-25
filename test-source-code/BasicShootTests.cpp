#include "trompeloeil.hpp"
#include "doctest.h"
#include "../game-source-code/BackEndSystems/RepositoryInterface.h"
#include "../game-source-code/FrontEndSystems/GameObject.h"
#include "../game-source-code/FrontEndSystems/Scene.h"
#include "../game-source-code/FrontEndSystems/Projectile.h"
#include "../game-source-code/FrontEndSystems/BasicShoot.h"
extern template struct trompeloeil::reporter<trompeloeil::specialized>;

class MockScene : public Scene
{
public: 
	MAKE_MOCK1(Instantiate, void(std::shared_ptr<GameObject>), override);
};

class MockRepository: public RepositioryInterface
{
public:
	MAKE_CONST_MOCK0(getGameScenes, std::vector<std::shared_ptr<Scene>>(void), override);
	MAKE_CONST_MOCK1(getGameObjectbyTypeDuringRuntime, std::shared_ptr<GameObject>(GameObjectType), override);
	MAKE_CONST_MOCK0(getGameScreenSize, std::vector<unsigned int>(void), override);
	MAKE_CONST_MOCK0(getGameName, std::string(void), override);
};
class MockProjectile: public Projectile
{
public:
	MAKE_MOCK2(Initialise, void(const Vector2D&, const Vector2D&), override);
	MAKE_MOCK0(DestroySelf, void(void));
};

TEST_CASE("1. Check that Basic Shoot implementation is working correctly")
{
	auto mockScene = std::make_shared<MockScene>();
	auto mockRepository = std::make_shared<MockRepository>();
	auto mockProjectile = std::make_shared<MockProjectile>();
	auto testStartPos = Vector2D::origin;
	auto testTarget = Vector2D::right;
	REQUIRE_CALL(*mockRepository, getGameObjectbyTypeDuringRuntime(GameObjectType::gameObject)).RETURN(mockProjectile);
	REQUIRE_CALL(*mockScene, Instantiate(ANY(std::shared_ptr<GameObject>)));
	REQUIRE_CALL(*mockProjectile, Initialise(testStartPos,testTarget));
	BasicShoot testShoot{GameObjectType::gameObject};
	testShoot.Shoot(testStartPos, testTarget, mockScene, mockRepository);
}