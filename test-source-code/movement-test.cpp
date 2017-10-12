#include "doctest.h"
#include "../game-source-code/Vector2D.h"
#include "../game-source-code/FrontEndSystems/MovableObject.h"
#include <iostream>

TEST_CASE("1.1: Move left"){
    Vector2D myVec1(1,1);
    Vector2D myVec2(-1,1);
    Vector2D myVec3(-1,-1);
    Vector2D myVec4(1,-1);
    auto speed = 2;
    
    Vector2D testVec1(-1,1);
    Vector2D testVec2(-3,1);
    Vector2D testVec3(-3,-1);
    Vector2D testVec4(-1,-1);
    
    MovableObject movable;
    
    movable.moveLeft(myVec1,speed);
    movable.moveLeft(myVec2,speed);
    movable.moveLeft(myVec3,speed);
    movable.moveLeft(myVec4,speed);
    
    SUBCASE("1.1.1: position moves left for position in quadrant 1." )
	{
        CHECK(doctest::Approx(myVec1.getXYVector().x) == testVec1.getXYVector().x);
        CHECK(doctest::Approx(myVec1.getXYVector().y) == testVec1.getXYVector().y);
	}
    
    SUBCASE("1.1.2: position moves left for position in quadrant 2." )
	{
        CHECK(doctest::Approx(myVec2.getXYVector().x) == testVec2.getXYVector().x);
        CHECK(doctest::Approx(myVec2.getXYVector().y) == testVec2.getXYVector().y);
	}
    
    SUBCASE("1.1.3: position moves left for position in quadrant 3." )
	{
        CHECK(doctest::Approx(myVec3.getXYVector().x) == testVec3.getXYVector().x);
        CHECK(doctest::Approx(myVec3.getXYVector().y) == testVec3.getXYVector().y);
	}
    
    SUBCASE("1.1.4: position moves left for position in quadrant 4." )
	{
        CHECK(doctest::Approx(myVec4.getXYVector().x) == testVec4.getXYVector().x);
        CHECK(doctest::Approx(myVec4.getXYVector().y) == testVec4.getXYVector().y);
	}
}

TEST_CASE("1.2: Move Right"){
    Vector2D myVec1(1,1,0);
    Vector2D myVec2(-1,1,0);
    Vector2D myVec3(-1,-1,0);
    Vector2D myVec4(1,-1,0);
    auto speed = 2;
    
    Vector2D testVec1(3,1,0);
    Vector2D testVec2(1,1,0);
    Vector2D testVec3(1,-1,0);
    Vector2D testVec4(3,-1,0);
    
    MovableObject movable;
    
    movable.moveRight(myVec1,speed);
    movable.moveRight(myVec2,speed);
    movable.moveRight(myVec3,speed);
    movable.moveRight(myVec4,speed);
    
    SUBCASE("1.2.1: position moves right for position in quadrant 1." )
	{
        CHECK(doctest::Approx(myVec1.getXYVector()) == testVec1.getXYVector());
        CHECK(doctest::Approx(myVec1.getXYVector()) == testVec1.getXYVector());
        CHECK(doctest::Approx(myVec1.getXYVector()) == testVec1.getXYVector());
	}
    
    SUBCASE("1.2.2: position moves right for position in quadrant 2." )
	{
        CHECK(doctest::Approx(myVec2.getXYVector()) == testVec2.getXYVector());
        CHECK(doctest::Approx(myVec2.getXYVector()) == testVec2.getXYVector());
        CHECK(doctest::Approx(myVec2.getXYVector()) == testVec2.getXYVector());
	}
    
    SUBCASE("1.2.3: position moves right for position in quadrant 3." )
	{
        CHECK(doctest::Approx(myVec3.getXYVector()) == testVec3.getXYVector());
        CHECK(doctest::Approx(myVec3.getXYVector()) == testVec3.getXYVector());
        CHECK(doctest::Approx(myVec3.getXYVector()) == testVec3.getXYVector());
	}
    
    SUBCASE("1.2.4: position moves right for position in quadrant 4." )
	{
        CHECK(doctest::Approx(myVec4.getXYVector()) == testVec4.getXYVector());
        CHECK(doctest::Approx(myVec4.getXYVector()) == testVec4.getXYVector());
        CHECK(doctest::Approx(myVec4.getXYVector()) == testVec4.getXYVector());
	}
}

TEST_CASE("1.3: Move Up"){
    Vector2D myVec1(1,1,0);
    Vector2D myVec2(-1,1,0);
    Vector2D myVec3(-1,-1,0);
    Vector2D myVec4(1,-1,0);
    auto speed = 2;
    
    Vector2D testVec1(1,3,0);
    Vector2D testVec2(-1,3,0);
    Vector2D testVec3(-1,1,0);
    Vector2D testVec4(1,1,0);
    
    MovableObject movable;
    
    movable.moveUp(myVec1,speed);
    movable.moveUp(myVec2,speed);
    movable.moveUp(myVec3,speed);
    movable.moveUp(myVec4,speed);
    
    SUBCASE("1.3.1: position moves up for position in quadrant 1." )
	{
        CHECK(doctest::Approx(myVec1.getXYVector()) == testVec1.getXYVector());
        CHECK(doctest::Approx(myVec1.getXYVector()) == testVec1.getXYVector());
        CHECK(doctest::Approx(myVec1.getXYVector()) == testVec1.getXYVector());
	}
    
    SUBCASE("1.3.2: position moves up for position in quadrant 2." )
	{
        CHECK(doctest::Approx(myVec2.getXYVector()) == testVec2.getXYVector());
        CHECK(doctest::Approx(myVec2.getXYVector()) == testVec2.getXYVector());
        CHECK(doctest::Approx(myVec2.getXYVector()) == testVec2.getXYVector());
	}
    
    SUBCASE("1.3.3: position moves up for position in quadrant 3." )
	{
        CHECK(doctest::Approx(myVec3.getXYVector()) == testVec3.getXYVector());
        CHECK(doctest::Approx(myVec3.getXYVector()) == testVec3.getXYVector());
        CHECK(doctest::Approx(myVec3.getXYVector()) == testVec3.getXYVector());
	}
    
    SUBCASE("1.3.4: position moves up for position in quadrant 4." )
	{
        CHECK(doctest::Approx(myVec4.getXYVector()) == testVec4.getXYVector());
        CHECK(doctest::Approx(myVec4.getXYVector()) == testVec4.getXYVector());
        CHECK(doctest::Approx(myVec4.getXYVector()) == testVec4.getXYVector());
	}
}

TEST_CASE("1.4: Move Down"){
    Vector2D myVec1(1,1,0);
    Vector2D myVec2(-1,1,0);
    Vector2D myVec3(-1,-1,0);
    Vector2D myVec4(1,-1,0);
    auto speed = 2;
    
    Vector2D testVec1(1,-1,0);
    Vector2D testVec2(-1,-1,0);
    Vector2D testVec3(-1,-3,0);
    Vector2D testVec4(1,-3,0);
    
    MovableObject movable;
    
    movable.moveDown(myVec1,speed);
    movable.moveDown(myVec2,speed);
    movable.moveDown(myVec3,speed);
    movable.moveDown(myVec4,speed);
    
    SUBCASE("1.4.1: position moves up for position in quadrant 1." )
	{
        CHECK(doctest::Approx(myVec1.getXYVector()) == testVec1.getXYVector());
        CHECK(doctest::Approx(myVec1.getXYVector()) == testVec1.getXYVector());
        CHECK(doctest::Approx(myVec1.getXYVector()) == testVec1.getXYVector());
	}
    
    SUBCASE("1.4.2: position moves up for position in quadrant 2." )
	{
        CHECK(doctest::Approx(myVec2.getXYVector()) == testVec2.getXYVector());
        CHECK(doctest::Approx(myVec2.getXYVector()) == testVec2.getXYVector());
        CHECK(doctest::Approx(myVec2.getXYVector()) == testVec2.getXYVector());
	}
    
    SUBCASE("1.4.3: position moves up for position in quadrant 3." )
	{
        CHECK(doctest::Approx(myVec3.getXYVector()) == testVec3.getXYVector());
        CHECK(doctest::Approx(myVec3.getXYVector()) == testVec3.getXYVector());
        CHECK(doctest::Approx(myVec3.getXYVector()) == testVec3.getXYVector());
	}
    
    SUBCASE("1.4.4: position moves up for position in quadrant 4." )
	{
        CHECK(doctest::Approx(myVec4.getXYVector()) == testVec4.getXYVector());
        CHECK(doctest::Approx(myVec4.getXYVector()) == testVec4.getXYVector());
        CHECK(doctest::Approx(myVec4.getXYVector()) == testVec4.getXYVector());
	}
}

TEST_CASE("2.1: Rotate Clockwise"){
    Vector2D myVec1(2,M_PI_4,0,VectorType::rtp);
    auto speed = M_PI/8;
    Vector2D testVec1(2,M_PI/8,0,VectorType::rtp);
    
    MovableObject movable;
    
    movable.rotateClockwise(myVec1,speed);
    
    SUBCASE("2.1.1: Rotate clockwise about the centre")
    {
        CHECK(doctest::Approx(myVec1.getXYVector()) == testVec1.getXYVector());
        CHECK(doctest::Approx(myVec1.getXYVector()) == testVec1.getXYVector());
        CHECK(doctest::Approx(myVec1.getXYVector()) == testVec1.getXYVector());
    }
    Vector2D myVec2(2,M_PI_4,0,VectorType::rtp);
    Vector2D centreVec(2.797932652,0.529902789,0,VectorType::rtp);
    Vector2D testVec2(2.334505443,0.878382581,0,VectorType::rtp);
    
    movable.rotateClockwise(myVec2,speed,centreVec);
    
    SUBCASE("2.1.2: Rotate clockwise about a non-centre point")
    {
        CHECK(doctest::Approx(myVec2.getXYVector()) == testVec2.getXYVector());
        CHECK(doctest::Approx(myVec2.getXYVector()) == testVec2.getXYVector());
        CHECK(doctest::Approx(myVec2.getXYVector()) == testVec2.getXYVector());
    }
}

TEST_CASE("2.2: Rotate Anti-clockwise"){
    Vector2D myVec1(2,M_PI_4,0,VectorType::rtp);
    auto speed = M_PI/8;
    Vector2D testVec1(2,3*M_PI/8,0,VectorType::rtp);
    
    MovableObject movable;
    
    movable.rotateAntiClockwise(myVec1,speed);
    
    SUBCASE("2.1.1: Rotate anti-clockwise about the centre")
    {
        CHECK(doctest::Approx(myVec1.getXYVector()) == testVec1.getXYVector());
        CHECK(doctest::Approx(myVec1.getXYVector()) == testVec1.getXYVector());
        CHECK(doctest::Approx(myVec1.getXYVector()) == testVec1.getXYVector());
    }
    Vector2D myVec2(2,M_PI_4,0,VectorType::rtp);
    Vector2D centreVec(2.797932652,0.529902789,0,VectorType::rtp);
    Vector2D testVec2(1.812493698,0.605442758,0,VectorType::rtp);
    
    movable.rotateAntiClockwise(myVec2,speed,centreVec);
    
    SUBCASE("2.1.2: Rotate anti-clockwise about a non-centre point")
    {
        CHECK(doctest::Approx(myVec2.getXYVector()) == testVec2.getXYVector());
        CHECK(doctest::Approx(myVec2.getXYVector()) == testVec2.getXYVector());
        CHECK(doctest::Approx(myVec2.getXYVector()) == testVec2.getXYVector());
    }
}