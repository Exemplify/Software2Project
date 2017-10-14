#include "doctest.h"
#include "trompeloeil.hpp"
#include "../game-source-code/BackEndSystems/DataMapper.h"
#include "../game-source-code/BackEndSystems/DatabaseInterface.h"

#include <string>
extern template struct trompeloeil::reporter<trompeloeil::specialized>;

class MockDatabaseInterface: public DatabaseInterface
{
public:
	MAKE_MOCK0(getGameStateData, GameStateData(void), override);
	MAKE_MOCK1(getGameObjectData, GameObjectData(std::string), override);
	MAKE_MOCK1(setGameStateData, void(GameStateData), override);
	MAKE_MOCK2(setGameObjectData, void(std::string, GameObjectData), override);
};

TEST_CASE("1.0 Test that DataMapper is succesfully assigning the data from the text files")
{
	auto MockDatabase_ptr = std::make_shared<MockDatabaseInterface>();
	DataMapper testMapper{"game_data/testobjectdata.txt", "game_data/teststatedata.txt"};
	GameStateData statetestData{1920, 1080, "#TestName"};
	GameObjectData objecttestData{1, 2, 3, 4, "5", "6", 7, 8, 9, 10, 11, 12, 13, 14, 15};
	std::string testID = "Test";
	REQUIRE_CALL(*MockDatabase_ptr, setGameObjectData(testID, objecttestData));
	REQUIRE_CALL(*MockDatabase_ptr, setGameStateData(statetestData));
	testMapper.UpdateGameTimeDatabase(MockDatabase_ptr);
}
