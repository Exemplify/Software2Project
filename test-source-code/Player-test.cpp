#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Player.h"

TEST_CASE("1: Test Players are initialised correctly"){
    Vector2D<double> testPosition1;
    Vector2D<double> testPosition2(1,2,3);
    
    Player player1(testPosition1);
    Player player2(testPosition2);
    
    CHECK(player1.getPosition() == testPosition1);
    CHECK(player2.getPosition() == testPosition2);
}