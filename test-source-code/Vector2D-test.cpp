#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Vector2D.cpp" //need to make compatable with .h file

// simple test on Vector2D constructor
TEST_CASE("1.1: A Vector2D object can be created correctly and returned"){
    vector<float> testvec = {1,2,3};
    Vector2D<float> myVecObj(testvec);
    vector<float> xyp_ret = myVecObj.xypVector();
    vector<float> rtp_ret = myVecObj.rtpVector();
    
    CHECK(xyp_ret.at(0)==testvec.at(0));
    CHECK(xyp_ret.at(1)==testvec.at(1));
    CHECK(xyp_ret.at(2)==testvec.at(2));
    
    CHECK(doctest::Approx(rtp_ret.at(0))==sqrt(5));
    CHECK(doctest::Approx(rtp_ret.at(1))==atan2(2,1));
    CHECK(rtp_ret.at(2)==testvec.at(2));
}

// define the overload operator == and test
TEST_CASE("2.1: Vector2D objects with identical parameters are equal"){
    vector<float> tempvec = {1,2,3};
    
    Vector2D<float> myVecObj1(tempvec);
    Vector2D<float> myVecObj2(tempvec);
    
    CHECK(myVecObj1==myVecObj2);
}

TEST_CASE("2.2: Vector2D objects with different x are inequal"){
    Vector2D<float> myVecObj1(vector<float> {1,2,3});
    Vector2D<float> myVecObj2(vector<float> {0,2,3});
    
    CHECK_FALSE(myVecObj1==myVecObj2);
}

TEST_CASE("2.3: Vector2D objects with different y are inequal"){
    Vector2D<float> myVecObj1(vector<float> {1,2,3});
    Vector2D<float> myVecObj2(vector<float> {1,0,3});
    
    CHECK_FALSE(myVecObj1==myVecObj2);
}

TEST_CASE("2.4: Vector2D objects with different phi (rotation) are inequal"){
    Vector2D<float> myVecObj1(vector<float> {1,2,3});
    Vector2D<float> myVecObj2(vector<float> {1,2,0});
    
    CHECK_FALSE(myVecObj1==myVecObj2);
}

// more vigorous constructor testing and specific vector case testing
TEST_CASE("3.1: Vector2D throws VectorSizeError if vector in constructor is not of size 3"){
    CHECK_THROWS_AS(Vector2D<float> myVecObj(vector<float> {1,2}), VectorSizeError);
    CHECK_THROWS_AS(Vector2D<float> myVecObj(vector<float> {1,2,3,4}), VectorSizeError);
}

TEST_CASE("3.2: vector at origin"){
    float x = 0, y = 0, p = 0;
    Vector2D<float> myVecObj(vector<float> {x,y,p});
    
    float r = sqrt(pow(x,2)+pow(y,2));
    float t = 0;
    vector<float> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.3: vector on + x-axis has the angle = 0 "){
    float x = 1, y = 0, p = 0;
    Vector2D<float> myVecObj(vector<float> {x,y,p});
    
    float r = sqrt(pow(x,2)+pow(y,2));
    float t = 0;
    vector<float> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.4: vector in first quadrant, angle = pi/4"){
    float x = 1, y = 1, p = 0;
    Vector2D<float> myVecObj(vector<float> {x,y,p});
    
    float r = sqrt(pow(x,2)+pow(y,2));
    float t = M_PI_4;
    vector<float> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.5: vector on + y-axis has angle = pi/2"){
    float x = 0, y = 1, p = 0;
    Vector2D<float> myVecObj(vector<float> {x,y,p});
    
    float r = sqrt(pow(x,2)+pow(y,2));
    float t = M_PI_2;
    vector<float> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.6: vector in second quadrant, angle = 3/4 pi"){
    float x = -1, y = 1, p = 0;
    Vector2D<float> myVecObj(vector<float> {x,y,p});
    
    float r = sqrt(pow(x,2)+pow(y,2));
    float t = 3*M_PI_4;
    vector<float> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.7: vector on - x-axis has angle = pi"){
    float x = -1, y = 0, p = 0;
    Vector2D<float> myVecObj(vector<float> {x,y,p});
    
    float r = sqrt(pow(x,2)+pow(y,2));
    float t = M_PI;
    vector<float> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.8: vector in third quadrant, angle = -3/4 pi"){
    float x = -1, y = -1, p = 0;
    Vector2D<float> myVecObj(vector<float> {x,y,p});
    
    float r = sqrt(pow(x,2)+pow(y,2));
    float t = -3*M_PI_4;
    vector<float> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.9: vector on - y-axis has angle = -pi/2"){
    float x = 0, y = -1, p = 0;
    Vector2D<float> myVecObj(vector<float> {x,y,p});
    
    float r = sqrt(pow(x,2)+pow(y,2));
    float t = -M_PI_2;
    vector<float> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.10: vector in fourth quadrant, angle = -pi/4"){
    float x = 1, y = -1, p = 0;
    Vector2D<float> myVecObj(vector<float> {x,y,p});
    
    float r = sqrt(pow(x,2)+pow(y,2));
    float t = -M_PI_4;
    vector<float> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}