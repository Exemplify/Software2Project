#include "doctest.h"
#include "trompeloeil.hpp"
#include "../game-source-code/BackEndSystems/Application.h"
#include "../game-source-code/BackEndSystems/GameManager.h"
#include "../game-source-code/FrontEndSystems/Scene.h"
#include "../game-source-code/FrontEndSystems/GameObject.h"
#include "../game-source-code/BackEndSystems/RepositoryInterface.h"
#include <memory>
#include <vector>
extern template struct trompeloeil::reporter<trompeloeil::specialized>;

class MockGameManager: public GameManager 
{
public:
	MockGameManager(std::shared_ptr<RepositioryInterface> repository): GameManager(repository) {}
	MAKE_MOCK1(LoadScene, void(unsigned int), override);
	MAKE_MOCK0(Exit, void(void), override);
	MAKE_MOCK0(GameLoop, void(void), override);
	MAKE_MOCK0(getSceneIndex,unsigned int(void), override);
};

class MockRepository: public RepositioryInterface
{
public:
	MAKE_CONST_MOCK0(getGameScenes, std::vector<std::shared_ptr<Scene>>(void), override);
	MAKE_CONST_MOCK1(getGameObjectbyTypeDuringRuntime, std::shared_ptr<GameObject>(GameObjectType), override);
	MAKE_CONST_MOCK0(getGameScreenSize, std::vector<unsigned int>(void), override);
	MAKE_CONST_MOCK0(getGameName, std::string(void), override);
};

TEST_CASE("Application Tests")
{
	auto mockRepository = std::make_shared<MockRepository>();
	ALLOW_CALL(*mockRepository, getGameScreenSize()).RETURN(std::vector<unsigned int>{1,1});
	ALLOW_CALL(*mockRepository, getGameName()).RETURN(std::string{"Test"});
	ALLOW_CALL(*mockRepository, getGameScenes()).RETURN(std::vector<std::shared_ptr<Scene>>{});
	auto mockGameManager = std::make_shared<MockGameManager>(mockRepository);
	Application testApplication(mockRepository, mockGameManager);
	SUBCASE("1. Application Successfully returns the Repositiory")
	{
		auto returnedRepository = Application::getGameRepository();
		CHECK_EQ(returnedRepository.get(), mockRepository.get());
	}
	SUBCASE("2. Application Successfully tells the GameManager to load a specific Scene")
	{
		auto testSceneIndex = 0u;
		REQUIRE_CALL(*mockGameManager, LoadScene(testSceneIndex));
		Application::LoadScene(testSceneIndex);
	}
	SUBCASE("3. Application Successfully tells the GameManager to Close the GameLoop")
	{
		REQUIRE_CALL(*mockGameManager, Exit());
		Application::CloseApplication();
	}
	SUBCASE("4. Application successfully starts the game")
	{
		REQUIRE_CALL(*mockGameManager, GameLoop());
		testApplication.RunApplication();
	}
}

