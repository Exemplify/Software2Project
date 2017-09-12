#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Vector2D.cpp" //need to make compatable with .h file

TEST_CASE("1: A Vector2D object can be created correctly and returned"){
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