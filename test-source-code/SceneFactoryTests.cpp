#include "MockDatabaseInterface.h"
#include "doctest.h"
#include "../game-source-code/BackEndSystems/GameSceneFactory.h"
#include "../game-source-code/BackEndSystems/WinSceneFactory.h"
#include "../game-source-code/BackEndSystems/LoseSceneFactory.h"



/////////////////////////////////////////////////////////////////////////////////////////////////
// The TEST_CASE_TEMPLATE is not picked up by doctest without this test case present in the file
//TEST_CASE("true")
//{
//	CHECK(true);
//}
typedef doctest::Types<GameSceneFactory,LoseSceneFactory,WinSceneFactory> the_types;


TEST_CASE_TEMPLATE_DEFINE("1 Test the various Scene Factories", T, test_id) 
{
	auto MockDatabase_ptr = std::make_shared<MockDatabaseInterface>();
	GameObjectData mockData{1, 2, 3, 4, "5", "6", 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	REQUIRE_CALL(*MockDatabase_ptr, getGameObjectData(ANY(std::string))).RETURN(mockData).TIMES(AT_LEAST(1));
	T factory;
	SUBCASE("1.1 Check that the GameObject list created has contains GameObjects")
	{
		auto testScene = factory.getScene(MockDatabase_ptr);
		auto gameObjList = testScene->getGameObjectList();
		CHECK(gameObjList.size() > 0);
	}
}

TEST_CASE_TEMPLATE_INSTANTIATE(test_id, the_types);