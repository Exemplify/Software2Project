#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Player.h"
#include <iostream>

TEST_CASE("1: Test Players are initialised correctly"){
    Vector2D<double> testPosition1;
    Vector2D<double> testPosition2(1,2,3);
    
    Player player1(testPosition1);
    Player player2(testPosition2);
    
    CHECK(player1.getPosition() == testPosition1);
    CHECK(player2.getPosition() == testPosition2);
}

TEST_CASE("2.1 Test Player is moving Left"){
    Vector2D<double> position(400,0,0);
    Vector2D<double> testPlayer1(0,-400,0);
    Vector2D<double> testPlayer2(0,400,0);
    Player player1(position);
    Player player2(position);
    
    for(auto i=0;i<100;i++)
        player1.TestMoveLeft();
    for(auto i=0;i<100;i++)
        player2.TestMoveRight();
    
    cout<<endl;
    cout<<player1.getPosition().xypVector().at(0)<<endl;
    cout<<player1.getPosition().xypVector().at(1)<<endl;
    cout<<player1.getPosition().xypVector().at(2)<<endl;
    cout<<endl;
    cout<<player2.getPosition().xypVector().at(0)<<endl;
    cout<<player2.getPosition().xypVector().at(1)<<endl;
    cout<<player2.getPosition().xypVector().at(2)<<endl;
    cout<<endl;
    
    CHECK(player1.getPosition() == testPlayer1);
    CHECK(player2.getPosition() == testPlayer2);
}
//magazine 
//	1 page missing 
//	2 total pages missing
//	total sum to 525 pages