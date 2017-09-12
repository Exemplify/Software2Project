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