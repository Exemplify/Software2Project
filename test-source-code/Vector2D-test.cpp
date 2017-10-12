#include "doctest.h"
#include <iostream>
#include <cmath>
#include "../game-source-code/Vector2D.h"

//===============================================================================================
//Section 1
// simple test on Vector2D constructor
TEST_CASE("1.1: A Vector2D object can be constructed in vector default (xy) form and returned"){
    xyVector xyVec = {1,2};
    Vector2D myVecObj(xyVec);
    xyVector test_xyVec = xyVec;
    rtVector test_rtVec = {sqrt(5), atan2(2,1)};
    
    xyVector ret_xyVec = myVecObj.getXYVector();
    rtVector ret_rtVec = myVecObj.getRTVector();
    
    SUBCASE("1.1.1: xy returned correctly")
    {
        CHECK(ret_xyVec.x == test_xyVec.x);
        CHECK(ret_xyVec.y == test_xyVec.y);
    }
    SUBCASE("1.1.2: rt returned correctly")
    {
        CHECK(doctest::Approx(ret_rtVec.r) == test_rtVec.r);
        CHECK(doctest::Approx(ret_rtVec.t) == test_rtVec.t);
    }
}

TEST_CASE("1.2: A Vector2D object can be constructed in vector (rt) form and returned"){
    rtVector rtVec = {sqrt(2),3*M_PI_4};
    Vector2D myVecObj(rtVec);
    xyVector test_xyVec = {-1,1};
    rtVector test_rtVec = rtVec;
    
    xyVector ret_xyVec = myVecObj.getXYVector();
    rtVector ret_rtVec = myVecObj.getRTVector();
    
    SUBCASE("1.2.1: xy returned correctly")
    {
        CHECK(doctest::Approx(ret_xyVec.x) == test_xyVec.x);
        CHECK(doctest::Approx(ret_xyVec.y )== test_xyVec.y);
    }
    SUBCASE("1.2.2: rt returned correctly")
    {
        CHECK(ret_rtVec.r == test_rtVec.r);
        CHECK(ret_rtVec.t == test_rtVec.t);
    }
}

TEST_CASE("1.3: A Vector2D object can be constructed in value default (xyp) form and returned"){
    double x = 1, y = 2;
    Vector2D myVecObj(x,y);
    xyVector ret_xyVec = myVecObj.getXYVector();
    rtVector ret_rtVec = myVecObj.getRTVector();
    
    SUBCASE("1.3.1: xy returned correctly")
    {
        CHECK(ret_xyVec.x == x);
        CHECK(ret_xyVec.y == y);
    }
    SUBCASE("1.3.2: rt returned correctly")
    {
        CHECK(doctest::Approx(ret_rtVec.r) == sqrt(5));
        CHECK(doctest::Approx(ret_rtVec.t) == atan2(y,x));
    }
}

TEST_CASE("1.4: A Vector2D object can be constructed in value rtp form and returned"){
    double r = sqrt(2), t = 3*M_PI_4;
    Vector2D myVecObj(r,t,VectorType::rt);
    xyVector ret_xyVec = myVecObj.getXYVector();
    rtVector ret_rtVec = myVecObj.getRTVector();
    
    SUBCASE("1.2.1: xy returned correctly")
    {
        CHECK(doctest::Approx(ret_xyVec.x) == -1);
        CHECK(doctest::Approx(ret_xyVec.y )== 1);
    }
    SUBCASE("1.2.2: rt returned correctly")
    {
        CHECK(ret_rtVec.r == r);
        CHECK(ret_rtVec.t == t);
    }
}

//===============================================================================================
//Section 2
// define the overload operator == and test
TEST_CASE("2.1: Vector2D objects with identical parameters are equal"){
    xyVector tempvec1 = {1,2};
    rtVector tempvec2 = {sqrt(5), atan2(2,1)};
    
    Vector2D myVecObj1(tempvec1);
    Vector2D myVecObj2(tempvec1);
    Vector2D myVecObj3(tempvec2);
    Vector2D myVecObj4(tempvec2);
    
    SUBCASE("2.1.1: both constructed in xy form")
    {
        CHECK(myVecObj1==myVecObj2);
    }
    SUBCASE("2.1.2: constructed in xy and rt form")
    {
        CHECK(myVecObj2==myVecObj3);
    }
    SUBCASE("2.1.3: both constructed in rt form")
    {
        CHECK(myVecObj3==myVecObj4);
    }
    
}

TEST_CASE("2.2: Vector2D objects with different x are inequal"){
    Vector2D myVecObj1(1,2);
    Vector2D myVecObj2(0,2);
    
    CHECK_FALSE(myVecObj1==myVecObj2);
}

TEST_CASE("2.3: Vector2D objects with different y are inequal"){
    Vector2D myVecObj1(1,2);
    Vector2D myVecObj2(1,0);
    
    CHECK_FALSE(myVecObj1==myVecObj2);
}

TEST_CASE("2.4: Vector2D objects with different r are inequal"){
    Vector2D myVecObj1(sqrt(2),3*M_PI_4,VectorType::rt);
    Vector2D myVecObj2(0,3*M_PI_4,VectorType::rt);
    
    CHECK_FALSE(myVecObj1==myVecObj2);
}

TEST_CASE("2.5: Vector2D objects with different t are inequal"){
    Vector2D myVecObj1(sqrt(2),3*M_PI_4,VectorType::rt);
    Vector2D myVecObj2(sqrt(2),0,VectorType::rt);
    
    CHECK_FALSE(myVecObj1==myVecObj2);
}

//===============================================================================================
//Section 3
// more vigorous constructor testing and specific vector case testing

TEST_CASE("3.1: vector at origin"){
    double x = 0, y = 0;
    Vector2D myVecObj(x,y);
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = 0;
    
    CHECK(myVecObj.getRTVector().r == r);
    CHECK(myVecObj.getRTVector().t == t);
    CHECK(Vector2D::magnitude(myVecObj) == 0);
}

TEST_CASE("3.2: vector on + x-axis has the angle = 0 "){
    double x = 1, y = 0;
    Vector2D myVecObj(x,y);
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = 0;
    
    CHECK(myVecObj.getRTVector().r == r);
    CHECK(myVecObj.getRTVector().t == t);
    CHECK(Vector2D::magnitude(myVecObj) == 1);
}

TEST_CASE("3.3: vector in first quadrant, angle = pi/4"){
    double x = 1, y = 1;
    Vector2D myVecObj(x,y);
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = M_PI_4;
    
    CHECK(myVecObj.getRTVector().r == r);
    CHECK(myVecObj.getRTVector().t == t);
    CHECK(Vector2D::magnitude(myVecObj) == sqrt(2));
}

TEST_CASE("3.4: vector on + y-axis has angle = pi/2"){
    double x = 0, y = 1;
    Vector2D myVecObj(x,y);
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = M_PI_2;
    
    CHECK(myVecObj.getRTVector().r == r);
    CHECK(myVecObj.getRTVector().t == t);
    CHECK(Vector2D::magnitude(myVecObj) == 1);
}

TEST_CASE("3.5: vector in second quadrant, angle = 3/4 pi"){
    double x = -1, y = 1;
    Vector2D myVecObj(x,y);
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = 3*M_PI_4;
    
    CHECK(myVecObj.getRTVector().r == r);
    CHECK(myVecObj.getRTVector().t == t);
    CHECK(Vector2D::magnitude(myVecObj) == sqrt(2));
}

TEST_CASE("3.6: vector on - x-axis has angle = pi"){
    double x = -1, y = 0;
    Vector2D myVecObj(x,y);
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = M_PI;
    
    CHECK(myVecObj.getRTVector().r == r);
    CHECK(myVecObj.getRTVector().t == t);
    CHECK(Vector2D::magnitude(myVecObj) == 1);
}

TEST_CASE("3.7: vector in third quadrant, angle = -3/4 pi"){
    double x = -1, y = -1;
    Vector2D myVecObj(x,y);
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = -3*M_PI_4;
    
    CHECK(myVecObj.getRTVector().r == r);
    CHECK(myVecObj.getRTVector().t == t);
    CHECK(Vector2D::magnitude(myVecObj) == sqrt(2));
}

TEST_CASE("3.8: vector on - y-axis has angle = -pi/2"){
    double x = 0, y = -1;
    Vector2D myVecObj(x,y);
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = -M_PI_2;
    
    CHECK(myVecObj.getRTVector().r == r);
    CHECK(myVecObj.getRTVector().t == t);
    CHECK(Vector2D::magnitude(myVecObj) == 1);
}

TEST_CASE("3.9: vector in fourth quadrant, angle = -pi/4"){
    double x = 1, y = -1;
    Vector2D myVecObj(x,y);
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = -M_PI_4;
    
    CHECK(myVecObj.getRTVector().r == r);
    CHECK(myVecObj.getRTVector().t == t);
    CHECK(Vector2D::magnitude(myVecObj) == sqrt(2));
}

//===============================================================================================
//Section 4
// magnitude function testing
TEST_CASE("4.1: Basic magnitude function test"){
    Vector2D myVecObj1(1,1);
    Vector2D myVecObj2(-1,1);
    
    CHECK(doctest::Approx(Vector2D::magnitude(myVecObj1,myVecObj2))==2);
}

TEST_CASE("4.2: Magnitude of one vector element is with reference to origin"){
    Vector2D myVecObj(1,1);
    CHECK(doctest::Approx(Vector2D::magnitude(myVecObj)) == sqrt(2));
    CHECK(doctest::Approx(Vector2D::magnitude(myVecObj)) == myVecObj.getRTVector().r);
}

//===============================================================================================
//Section 5
// Other operator overloads defined and tested

// the addition operator
TEST_CASE("5.1: The addition + of two Vector2Ds (in rt declared form)"){
    Vector2D myVecObj1(1,M_PI/8, VectorType::rt);
    Vector2D myVecObj2(1,(5*M_PI/8), VectorType::rt);
    Vector2D vecTest (sqrt(2),(3*M_PI/8), VectorType::rt);
    
    Vector2D addedVec = myVecObj1+myVecObj2;
    
    CHECK(addedVec == vecTest);
}

// the addition operator
TEST_CASE("5.2: The addition + of two Vector2Ds (in xy declared form)"){
    Vector2D myVecObj1(1,2);
    Vector2D myVecObj2(4,5);
    Vector2D myVecTest(5,7);
    
    Vector2D addedVec = myVecObj1+myVecObj2;
    
    CHECK(addedVec == myVecTest);
}

// the subtraction operator
TEST_CASE("5.3: The subtraction - of two Vector2Ds (in rt declared form)"){
    Vector2D myVecObj1(1,M_PI/8, VectorType::rt);
    Vector2D myVecObj2(1,(5*M_PI/8), VectorType::rt);
    Vector2D vecTest(sqrt(2),(-M_PI/8), VectorType::rt);
    
    Vector2D subtractedVec = myVecObj1-myVecObj2;
    
    CHECK(subtractedVec == vecTest);
}

// the subtraction operator
TEST_CASE("5.4: The subtraction - of two Vector2Ds (in xy declared form)"){
    Vector2D myVecObj1(4,5);
    Vector2D myVecObj2(1,2);
    Vector2D myVecTest(3,3);
    
    Vector2D subtractedVec = myVecObj1-myVecObj2;
    
    CHECK(subtractedVec == myVecTest);
}

//the Vector2D multiply operator
TEST_CASE("5.5: The Vector2D multiply * of two Vector2Ds (in rt declared form)"){
    Vector2D myVecObj1(2,1, VectorType::rt);
    Vector2D myVecObj2(3,2, VectorType::rt);
    Vector2D myVecTest(6,3, VectorType::rt);
    
    CHECK((myVecObj1*myVecObj2) == myVecTest);
}


//the Vector2D multiply operator
TEST_CASE("5.6: The Vector2D multiply * of two Vector2Ds (in xy declared form)"){
    Vector2D myVecObj1(1,2);
    Vector2D myVecObj2(4,5);
    Vector2D myVecTest(-6,13);
    
    CHECK((myVecObj1*myVecObj2) == myVecTest);
}

//the Vector2D scalar multiply operator
TEST_CASE("5.7: The scalar multiply * of a Vector2D (in rt declared form)"){
    Vector2D myVec(2,1, VectorType::rt);
    Vector2D vecTest(-4*M_PI,1, VectorType::rt);
    double scalar = -2*M_PI;
    
    Vector2D vecProd = myVec*scalar;
    
    CHECK(vecProd == vecTest);
}

//the Vector2D scalar multiply operator
TEST_CASE("5.8: The scalar multiply * of a Vector2D (in xy declared form)"){
    Vector2D myVec(1,2);
    Vector2D vecTest(-M_PI,-2*M_PI);
    double scalar = -M_PI;
    
    Vector2D vecProd = myVec*scalar;
    
    CHECK(vecProd == vecTest);
}

//the Vector2D scalar division operator
TEST_CASE("5.9: The scalar division / of a Vector2D (in rt declared form)"){
    Vector2D myVec(2*M_PI,1, VectorType::rt);
    Vector2D vecTest(-2,1, VectorType::rt);
    double scalar = -M_PI;
    
    Vector2D vecProd = myVec/scalar;
    
    CHECK(vecProd == vecTest);
}

//the Vector2D scalar multiply operator
TEST_CASE("5.10: The scalar division / of a Vector2D (in xy declared form)"){
    Vector2D myVec (M_PI,2*M_PI);
    Vector2D vecTest(-1,-2);
    double scalar = -M_PI;
    
    Vector2D vecProd = myVec/scalar;
    
    CHECK(vecProd == vecTest);
}


// the addition assignment operator
TEST_CASE("5.11: The addition assignment += of two Vector2Ds (in rt declared form)"){
    Vector2D myVecObj1(1,M_PI/8, VectorType::rt);
    Vector2D myVecObj2(1,(5*M_PI/8), VectorType::rt);
    Vector2D  vecTest(sqrt(2),(3*M_PI/8), VectorType::rt);
    
    myVecObj1+=myVecObj2;
    
    CHECK(myVecObj1 == vecTest);
}

// the addition assignment operator
TEST_CASE("5.12: The addition assignment += of two Vector2Ds (in xy declared form)"){
    Vector2D myVecObj1(1,2);
    Vector2D myVecObj2(4,5);
    Vector2D myVecTest(5,7);
    
    myVecObj1+=myVecObj2;
    
    CHECK(myVecObj1 == myVecTest);
}

// the subtraction assignment operator
TEST_CASE("5.11: The subtraction assignment -= of two Vector2Ds (in rt declared form)"){
    Vector2D myVecObj1(1,M_PI/8, VectorType::rt);
    Vector2D myVecObj2(1,(5*M_PI/8), VectorType::rt);
    Vector2D vecTest(sqrt(2),(-M_PI/8), VectorType::rt);
    
    myVecObj1-=myVecObj2;
    
    CHECK(myVecObj1 == vecTest);
}

// the addition assignment operator
TEST_CASE("5.12: The addition assignment -= of two Vector2Ds (in xy declared form)"){
    Vector2D myVecObj1(4,5);
    Vector2D myVecObj2(1,2);
    Vector2D myVecTest(3,3);
    
    myVecObj1-=myVecObj2;
    
    CHECK(myVecObj1 == myVecTest);
}

// the scalar multiple assignment operator
TEST_CASE("5.13: The scalar multiple and assignment *= opperator on a Vector2D (in rt declared form)"){
    Vector2D myVec(2,1, VectorType::rt);
    Vector2D vecTest (-4*M_PI,1, VectorType::rt);
    double scalar = -2*M_PI;
    
    myVec*=scalar;
    CHECK(myVec == vecTest);

}

// the scalar multiple assignment operator
TEST_CASE("5.14: The scalar multiple and assignment *= opperator on a Vector2D (in xy declared form)"){
    Vector2D myVec (1,2);
    Vector2D vecTest(-2*M_PI,-4*M_PI);
    double scalar = -2*M_PI;
    
    myVec*=scalar;
    
    CHECK(myVec == vecTest);
}

// the scalar division assignment operator
TEST_CASE("5.15: The scalar division and assignment /= opperator on a Vector2D (in rt declared form)"){
    Vector2D myVec(2*M_PI,1, VectorType::rt);
    Vector2D vecTest(-2,1, VectorType::rt);
    double scalar = -M_PI;
    
    myVec/=scalar;
    CHECK(myVec == vecTest);

}

// the scalar division assignment operator
TEST_CASE("5.16: The scalar division and assignment /= opperator on a Vector2D (in xy declared form)"){
    Vector2D myVec(M_PI,2*M_PI);
    Vector2D vecTest(-1,-2);
    double scalar = -M_PI;
    
    myVec/=scalar;
    
    CHECK(myVec == vecTest);
    
}

//===============================================================================================
//Section 6
// Normalise vector function
TEST_CASE("6.1: A Vector2D can be normalized (in rt declated form)"){
    Vector2D myVec(5,M_PI/8, VectorType::rt);
    Vector2D vecTest(1,M_PI/8, VectorType::rt);
    Vector2D normVec = myVec.normalize();
    
    CHECK(normVec == vecTest);
}

TEST_CASE("6.1: A Vector2D can be normalized (in xy declated form)"){
    Vector2D myVec(-1,2);
    Vector2D vecTest(1,atan2(2,-1), VectorType::rt);
    Vector2D normVec = myVec.normalize();
    
    CHECK(normVec == vecTest);
}