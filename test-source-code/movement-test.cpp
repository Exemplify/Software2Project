#include "doctest.h"
#include "../game-source-code/Vector2D.hpp"
#include "../game-source-code/FrontEndSystems/MovableObject.h"
#include <iostream>

TEST_CASE("1.1: Move left"){
    Vector2D<double> myVec1(1,1,0);
    Vector2D<double> myVec2(-1,1,0);
    Vector2D<double> myVec3(-1,-1,0);
    Vector2D<double> myVec4(1,-1,0);
    auto speed = 2;
    
    Vector2D<double> testVec1(-1,1,0);
    Vector2D<double> testVec2(-3,1,0);
    Vector2D<double> testVec3(-3,-1,0);
    Vector2D<double> testVec4(-1,-1,0);
    
    MovableObject movable;
    
    movable.moveLeft(myVec1,speed);
    movable.moveLeft(myVec2,speed);
    movable.moveLeft(myVec3,speed);
    movable.moveLeft(myVec4,speed);
    
    SUBCASE("1.1.1: position moves left for position in quadrant 1." )
	{
        CHECK(doctest::Approx(myVec1.xypVector().at(0)) == testVec1.xypVector().at(0));
        CHECK(doctest::Approx(myVec1.xypVector().at(1)) == testVec1.xypVector().at(1));
        CHECK(doctest::Approx(myVec1.xypVector().at(2)) == testVec1.xypVector().at(2));
	}
    
    SUBCASE("1.1.2: position moves left for position in quadrant 2." )
	{
        CHECK(doctest::Approx(myVec2.xypVector().at(0)) == testVec2.xypVector().at(0));
        CHECK(doctest::Approx(myVec2.xypVector().at(1)) == testVec2.xypVector().at(1));
        CHECK(doctest::Approx(myVec2.xypVector().at(2)) == testVec2.xypVector().at(2));
	}
    
    SUBCASE("1.1.3: position moves left for position in quadrant 3." )
	{
        CHECK(doctest::Approx(myVec3.xypVector().at(0)) == testVec3.xypVector().at(0));
        CHECK(doctest::Approx(myVec3.xypVector().at(1)) == testVec3.xypVector().at(1));
        CHECK(doctest::Approx(myVec3.xypVector().at(2)) == testVec3.xypVector().at(2));
	}
    
    SUBCASE("1.1.4: position moves left for position in quadrant 4." )
	{
        CHECK(doctest::Approx(myVec4.xypVector().at(0)) == testVec4.xypVector().at(0));
        CHECK(doctest::Approx(myVec4.xypVector().at(1)) == testVec4.xypVector().at(1));
        CHECK(doctest::Approx(myVec4.xypVector().at(2)) == testVec4.xypVector().at(2));
	}
}

TEST_CASE("1.2: Move Right"){
    Vector2D<double> myVec1(1,1,0);
    Vector2D<double> myVec2(-1,1,0);
    Vector2D<double> myVec3(-1,-1,0);
    Vector2D<double> myVec4(1,-1,0);
    auto speed = 2;
    
    Vector2D<double> testVec1(3,1,0);
    Vector2D<double> testVec2(1,1,0);
    Vector2D<double> testVec3(1,-1,0);
    Vector2D<double> testVec4(3,-1,0);
    
    MovableObject movable;
    
    movable.moveRight(myVec1,speed);
    movable.moveRight(myVec2,speed);
    movable.moveRight(myVec3,speed);
    movable.moveRight(myVec4,speed);
    
    SUBCASE("1.2.1: position moves right for position in quadrant 1." )
	{
        CHECK(doctest::Approx(myVec1.xypVector().at(0)) == testVec1.xypVector().at(0));
        CHECK(doctest::Approx(myVec1.xypVector().at(1)) == testVec1.xypVector().at(1));
        CHECK(doctest::Approx(myVec1.xypVector().at(2)) == testVec1.xypVector().at(2));
	}
    
    SUBCASE("1.2.2: position moves right for position in quadrant 2." )
	{
        CHECK(doctest::Approx(myVec2.xypVector().at(0)) == testVec2.xypVector().at(0));
        CHECK(doctest::Approx(myVec2.xypVector().at(1)) == testVec2.xypVector().at(1));
        CHECK(doctest::Approx(myVec2.xypVector().at(2)) == testVec2.xypVector().at(2));
	}
    
    SUBCASE("1.2.3: position moves right for position in quadrant 3." )
	{
        CHECK(doctest::Approx(myVec3.xypVector().at(0)) == testVec3.xypVector().at(0));
        CHECK(doctest::Approx(myVec3.xypVector().at(1)) == testVec3.xypVector().at(1));
        CHECK(doctest::Approx(myVec3.xypVector().at(2)) == testVec3.xypVector().at(2));
	}
    
    SUBCASE("1.2.4: position moves right for position in quadrant 4." )
	{
        CHECK(doctest::Approx(myVec4.xypVector().at(0)) == testVec4.xypVector().at(0));
        CHECK(doctest::Approx(myVec4.xypVector().at(1)) == testVec4.xypVector().at(1));
        CHECK(doctest::Approx(myVec4.xypVector().at(2)) == testVec4.xypVector().at(2));
	}
}

TEST_CASE("1.3: Move Up"){
    Vector2D<double> myVec1(1,1,0);
    Vector2D<double> myVec2(-1,1,0);
    Vector2D<double> myVec3(-1,-1,0);
    Vector2D<double> myVec4(1,-1,0);
    auto speed = 2;
    
    Vector2D<double> testVec1(1,3,0);
    Vector2D<double> testVec2(-1,3,0);
    Vector2D<double> testVec3(-1,1,0);
    Vector2D<double> testVec4(1,1,0);
    
    MovableObject movable;
    
    movable.moveUp(myVec1,speed);
    movable.moveUp(myVec2,speed);
    movable.moveUp(myVec3,speed);
    movable.moveUp(myVec4,speed);
    
    SUBCASE("1.3.1: position moves up for position in quadrant 1." )
	{
        CHECK(doctest::Approx(myVec1.xypVector().at(0)) == testVec1.xypVector().at(0));
        CHECK(doctest::Approx(myVec1.xypVector().at(1)) == testVec1.xypVector().at(1));
        CHECK(doctest::Approx(myVec1.xypVector().at(2)) == testVec1.xypVector().at(2));
	}
    
    SUBCASE("1.3.2: position moves up for position in quadrant 2." )
	{
        CHECK(doctest::Approx(myVec2.xypVector().at(0)) == testVec2.xypVector().at(0));
        CHECK(doctest::Approx(myVec2.xypVector().at(1)) == testVec2.xypVector().at(1));
        CHECK(doctest::Approx(myVec2.xypVector().at(2)) == testVec2.xypVector().at(2));
	}
    
    SUBCASE("1.3.3: position moves up for position in quadrant 3." )
	{
        CHECK(doctest::Approx(myVec3.xypVector().at(0)) == testVec3.xypVector().at(0));
        CHECK(doctest::Approx(myVec3.xypVector().at(1)) == testVec3.xypVector().at(1));
        CHECK(doctest::Approx(myVec3.xypVector().at(2)) == testVec3.xypVector().at(2));
	}
    
    SUBCASE("1.3.4: position moves up for position in quadrant 4." )
	{
        CHECK(doctest::Approx(myVec4.xypVector().at(0)) == testVec4.xypVector().at(0));
        CHECK(doctest::Approx(myVec4.xypVector().at(1)) == testVec4.xypVector().at(1));
        CHECK(doctest::Approx(myVec4.xypVector().at(2)) == testVec4.xypVector().at(2));
	}
}

TEST_CASE("1.4: Move Down"){
    Vector2D<double> myVec1(1,1,0);
    Vector2D<double> myVec2(-1,1,0);
    Vector2D<double> myVec3(-1,-1,0);
    Vector2D<double> myVec4(1,-1,0);
    auto speed = 2;
    
    Vector2D<double> testVec1(1,-1,0);
    Vector2D<double> testVec2(-1,-1,0);
    Vector2D<double> testVec3(-1,-3,0);
    Vector2D<double> testVec4(1,-3,0);
    
    MovableObject movable;
    
    movable.moveDown(myVec1,speed);
    movable.moveDown(myVec2,speed);
    movable.moveDown(myVec3,speed);
    movable.moveDown(myVec4,speed);
    
    SUBCASE("1.4.1: position moves up for position in quadrant 1." )
	{
        CHECK(doctest::Approx(myVec1.xypVector().at(0)) == testVec1.xypVector().at(0));
        CHECK(doctest::Approx(myVec1.xypVector().at(1)) == testVec1.xypVector().at(1));
        CHECK(doctest::Approx(myVec1.xypVector().at(2)) == testVec1.xypVector().at(2));
	}
    
    SUBCASE("1.4.2: position moves up for position in quadrant 2." )
	{
        CHECK(doctest::Approx(myVec2.xypVector().at(0)) == testVec2.xypVector().at(0));
        CHECK(doctest::Approx(myVec2.xypVector().at(1)) == testVec2.xypVector().at(1));
        CHECK(doctest::Approx(myVec2.xypVector().at(2)) == testVec2.xypVector().at(2));
	}
    
    SUBCASE("1.4.3: position moves up for position in quadrant 3." )
	{
        CHECK(doctest::Approx(myVec3.xypVector().at(0)) == testVec3.xypVector().at(0));
        CHECK(doctest::Approx(myVec3.xypVector().at(1)) == testVec3.xypVector().at(1));
        CHECK(doctest::Approx(myVec3.xypVector().at(2)) == testVec3.xypVector().at(2));
	}
    
    SUBCASE("1.4.4: position moves up for position in quadrant 4." )
	{
        CHECK(doctest::Approx(myVec4.xypVector().at(0)) == testVec4.xypVector().at(0));
        CHECK(doctest::Approx(myVec4.xypVector().at(1)) == testVec4.xypVector().at(1));
        CHECK(doctest::Approx(myVec4.xypVector().at(2)) == testVec4.xypVector().at(2));
	}
}

TEST_CASE("2.1: Rotate Clockwise"){
    Vector2D<double> myVec1(2,M_PI_4,0,VectorType::rtp);
    auto speed = M_PI/8;
    Vector2D<double> testVec1(2,M_PI/8,0,VectorType::rtp);
    
    MovableObject movable;
    
    movable.rotateClockwise(myVec1,speed);
    
    SUBCASE("2.1.1: Rotate clockwise about the centre")
    {
        CHECK(doctest::Approx(myVec1.xypVector().at(0)) == testVec1.xypVector().at(0));
        CHECK(doctest::Approx(myVec1.xypVector().at(1)) == testVec1.xypVector().at(1));
        CHECK(doctest::Approx(myVec1.xypVector().at(2)) == testVec1.xypVector().at(2));
    }
    Vector2D<double> myVec2(2,M_PI_4,0,VectorType::rtp);
    Vector2D<double> centreVec(2.797932652,0.529902789,0,VectorType::rtp);
    Vector2D<double> testVec2(2.334505443,0.878382581,0,VectorType::rtp);
    
    movable.rotateClockwise(myVec2,speed,centreVec);
    
    SUBCASE("2.1.2: Rotate clockwise about a non-centre point")
    {
        CHECK(doctest::Approx(myVec2.xypVector().at(0)) == testVec2.xypVector().at(0));
        CHECK(doctest::Approx(myVec2.xypVector().at(1)) == testVec2.xypVector().at(1));
        CHECK(doctest::Approx(myVec2.xypVector().at(2)) == testVec2.xypVector().at(2));
    }
}

TEST_CASE("2.2: Rotate Anti-clockwise"){
    Vector2D<double> myVec1(2,M_PI_4,0,VectorType::rtp);
    auto speed = M_PI/8;
    Vector2D<double> testVec1(2,3*M_PI/8,0,VectorType::rtp);
    
    MovableObject movable;
    
    movable.rotateAntiClockwise(myVec1,speed);
    
    SUBCASE("2.1.1: Rotate anti-clockwise about the centre")
    {
        CHECK(doctest::Approx(myVec1.xypVector().at(0)) == testVec1.xypVector().at(0));
        CHECK(doctest::Approx(myVec1.xypVector().at(1)) == testVec1.xypVector().at(1));
        CHECK(doctest::Approx(myVec1.xypVector().at(2)) == testVec1.xypVector().at(2));
    }
    Vector2D<double> myVec2(2,M_PI_4,0,VectorType::rtp);
    Vector2D<double> centreVec(2.797932652,0.529902789,0,VectorType::rtp);
    Vector2D<double> testVec2(1.812493698,0.605442758,0,VectorType::rtp);
    
    movable.rotateAntiClockwise(myVec2,speed,centreVec);
    
    SUBCASE("2.1.2: Rotate anti-clockwise about a non-centre point")
    {
        CHECK(doctest::Approx(myVec2.xypVector().at(0)) == testVec2.xypVector().at(0));
        CHECK(doctest::Approx(myVec2.xypVector().at(1)) == testVec2.xypVector().at(1));
        CHECK(doctest::Approx(myVec2.xypVector().at(2)) == testVec2.xypVector().at(2));
    }
}