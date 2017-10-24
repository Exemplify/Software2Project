#ifndef MOCK_DATABASE
#define MOCKDATABASE
#include "trompeloeil.hpp"
#include "../game-source-code/BackEndSystems/DatabaseInterface.h"

extern template struct trompeloeil::reporter<trompeloeil::specialized>;

class MockDatabaseInterface: public DatabaseInterface
{
public:
	MAKE_MOCK0(getGameStateData, GameStateData(void), override);
	MAKE_MOCK1(getGameObjectData, GameObjectData(std::string), override);
	MAKE_MOCK1(setGameStateData, void(GameStateData), override);
	MAKE_MOCK2(setGameObjectData, void(std::string, GameObjectData), override);
};
#endif