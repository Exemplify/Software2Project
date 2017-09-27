#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <cmath>
#include "Vector2D.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////
// Vector2D Tests

// simple test on Vector2D constructor
TEST_CASE("1.1: A Vector2D object can be constructed in vector default (xyp) form and returned"){
    vector<double> testvec = {1,2,3};
    Vector2D<double> myVecObj(testvec);
    vector<double> xyp_ret = myVecObj.xypVector();
    vector<double> rtp_ret = myVecObj.rtpVector();
    
    CHECK(xyp_ret.at(0)==testvec.at(0));
    CHECK(xyp_ret.at(1)==testvec.at(1));
    CHECK(xyp_ret.at(2)==testvec.at(2));
    
    CHECK(doctest::Approx(rtp_ret.at(0))==sqrt(5));
    CHECK(doctest::Approx(rtp_ret.at(1))==atan2(2,1));
    CHECK(rtp_ret.at(2)==testvec.at(2));
}

// test other constructor cases
TEST_CASE("1.2: A Vector2D object can be constructed in vector rtp form and returned"){
    vector<double> testvec = {sqrt(2),3*M_PI_4,3};
    Vector2D<double> myVecObj(testvec,VectorType::rtp);
    vector<double> xyp_ret = myVecObj.xypVector();
    vector<double> rtp_ret = myVecObj.rtpVector();
    
    CHECK(doctest::Approx(xyp_ret.at(0))==-1.0);
    CHECK(doctest::Approx(xyp_ret.at(1))==1.0);
    CHECK(xyp_ret.at(2)==3);
    
    CHECK(rtp_ret.at(0)==testvec.at(0));
    CHECK(rtp_ret.at(1)==testvec.at(1));
    CHECK(rtp_ret.at(2)==testvec.at(2));
}

TEST_CASE("1.3: A Vector2D object can be constructed in value default (xyp) form and returned"){
    double x = 1, y = 2, p = 3;
    Vector2D<double> myVecObj(x,y,p);
    vector<double> xyp_ret = myVecObj.xypVector();
    vector<double> rtp_ret = myVecObj.rtpVector();
    
    CHECK(xyp_ret.at(0) == x);
    CHECK(xyp_ret.at(1) == y);
    CHECK(xyp_ret.at(2) == p);
    
    CHECK(rtp_ret.at(0)==sqrt(5));
    CHECK(rtp_ret.at(1)==atan2(2,1));
    CHECK(rtp_ret.at(2) == p);
}

TEST_CASE("1.4: A Vector2D object can be constructed in value rtp form and returned"){
    double r = sqrt(2), t = 3*M_PI_4, p =3;
    Vector2D<double> myVecObj(r,t,p,VectorType::rtp);
    vector<double> xyp_ret = myVecObj.xypVector();
    vector<double> rtp_ret = myVecObj.rtpVector();
    
    CHECK(doctest::Approx(xyp_ret.at(0))==-1.0);
    CHECK(doctest::Approx(xyp_ret.at(1))==1.0);
    CHECK(xyp_ret.at(2)==p);
    
    CHECK(rtp_ret.at(0) == r);
    CHECK(rtp_ret.at(1) == t);
    CHECK(rtp_ret.at(2) == p);
}

// define the overload operator == and test
TEST_CASE("2.1: Vector2D objects with identical parameters are equal"){
    vector<double> tempvec = {1,2,3};
    
    Vector2D<double> myVecObj1(tempvec);
    Vector2D<double> myVecObj2(tempvec);
    
    CHECK(myVecObj1==myVecObj2);
}

TEST_CASE("2.2: Vector2D objects with different x are inequal"){
    Vector2D<double> myVecObj1(vector<double> {1,2,3});
    Vector2D<double> myVecObj2(vector<double> {0,2,3});
    
    CHECK_FALSE(myVecObj1==myVecObj2);
}

TEST_CASE("2.3: Vector2D objects with different y are inequal"){
    Vector2D<double> myVecObj1(vector<double> {1,2,3});
    Vector2D<double> myVecObj2(vector<double> {1,0,3});
    
    CHECK_FALSE(myVecObj1==myVecObj2);
}

TEST_CASE("2.4: Vector2D objects with different phi (rotation) are inequal"){
    Vector2D<double> myVecObj1(vector<double> {1,2,3});
    Vector2D<double> myVecObj2(vector<double> {1,2,0});
    
    CHECK_FALSE(myVecObj1==myVecObj2);
}

// more vigorous constructor testing and specific vector case testing
TEST_CASE("3.1: Vector2D throws VectorSizeError if vector in constructor is not of size 3"){
    CHECK_THROWS_AS(Vector2D<double> myVecObj(vector<double> {1,2}), VectorSizeError);
    CHECK_THROWS_AS(Vector2D<double> myVecObj(vector<double> {1,2,3,4}), VectorSizeError);
}

TEST_CASE("3.2: vector at origin"){
    double x = 0, y = 0, p = 0;
    Vector2D<double> myVecObj(vector<double> {x,y,p});
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = 0;
    vector<double> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.3: vector on + x-axis has the angle = 0 "){
    double x = 1, y = 0, p = 0;
    Vector2D<double> myVecObj(vector<double> {x,y,p});
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = 0;
    vector<double> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.4: vector in first quadrant, angle = pi/4"){
    double x = 1, y = 1, p = 0;
    Vector2D<double> myVecObj(vector<double> {x,y,p});
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = M_PI_4;
    vector<double> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.5: vector on + y-axis has angle = pi/2"){
    double x = 0, y = 1, p = 0;
    Vector2D<double> myVecObj(vector<double> {x,y,p});
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = M_PI_2;
    vector<double> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.6: vector in second quadrant, angle = 3/4 pi"){
    double x = -1, y = 1, p = 0;
    Vector2D<double> myVecObj(vector<double> {x,y,p});
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = 3*M_PI_4;
    vector<double> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.7: vector on - x-axis has angle = pi"){
    double x = -1, y = 0, p = 0;
    Vector2D<double> myVecObj(vector<double> {x,y,p});
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = M_PI;
    vector<double> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.8: vector in third quadrant, angle = -3/4 pi"){
    double x = -1, y = -1, p = 0;
    Vector2D<double> myVecObj(vector<double> {x,y,p});
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = -3*M_PI_4;
    vector<double> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.9: vector on - y-axis has angle = -pi/2"){
    double x = 0, y = -1, p = 0;
    Vector2D<double> myVecObj(vector<double> {x,y,p});
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = -M_PI_2;
    vector<double> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

TEST_CASE("3.10: vector in fourth quadrant, angle = -pi/4"){
    double x = 1, y = -1, p = 0;
    Vector2D<double> myVecObj(vector<double> {x,y,p});
    
    double r = sqrt(pow(x,2)+pow(y,2));
    double t = -M_PI_4;
    vector<double> testvec = {r,t,p};
    CHECK(myVecObj.rtpVector().at(0) == testvec.at(0));
    CHECK(myVecObj.rtpVector().at(1) == testvec.at(1));
    CHECK(myVecObj.rtpVector().at(2) == testvec.at(2));
}

// magnitude function testing
TEST_CASE("4.1: Basic magnitude function test"){
    Vector2D<double> myVecObj1(vector<double> {1,1,0});
    Vector2D<double> myVecObj2(vector<double> {-1,1,0});
    
    CHECK(doctest::Approx(Vector2D<double>::magnitude(myVecObj1,myVecObj2))==2);
}

TEST_CASE("4.2: Magnitude of one vector element is with reference to origin"){
    Vector2D<double> myVecObj(vector<double> {1,1,0});
    CHECK(doctest::Approx(Vector2D<double>::magnitude(myVecObj)) == sqrt(2));
    CHECK(doctest::Approx(Vector2D<double>::magnitude(myVecObj)) == myVecObj.rtpVector().at(0));
}

// Other bitwise operators defined
// the addition operator
TEST_CASE("5.1: The addition + of two Vector2Ds"){
    Vector2D<double> myVecObj1(vector<double> {1,2,3});
    Vector2D<double> myVecObj2(vector<double> {4,5,6});
    Vector2D<double> myVecTest(vector<double> {5,7,9});
    
    CHECK((myVecObj1+myVecObj2) == myVecTest);
}

//the subtraction operator
TEST_CASE("5.2: The subtraction - of two Vector2Ds"){
    Vector2D<double> myVecObj1(vector<double> {1,2,3});
    Vector2D<double> myVecObj2(vector<double> {4,5,6});
    Vector2D<double> myVecTest(vector<double> {3,3,3});
    
    CHECK((myVecObj2-myVecObj1) == myVecTest);
}

//the Vector2d multiply operator
TEST_CASE("5.3: The Vector2D multiply * of two Vector2ds (in rtp declared form)"){
    Vector2D<double> myVecObj1(vector<double> {1,2,3}, VectorType::rtp);
    Vector2D<double> myVecObj2(vector<double> {4,5,6}, VectorType::rtp);
    Vector2D<double> myVecTest(vector<double> {4,7,0}, VectorType::rtp);
    
    CHECK((myVecObj1*myVecObj2) == myVecTest);
}

//
////the Vector2D multiply operator
//TEST_CASE("5.4: The Vector2D multiply * of two Vector2Ds (in xyp declared form)"){
//    Vector2D<double> myVecObj1(vector<double> {1,2,3});
//    Vector2D<double> myVecObj2(vector<double> {4,5,6});
//    Vector2D<double> myVecTest(vector<double> {-6.0,13.0,0});
//    
//    Vector2D<double> myVecProduct = myVecObj1*myVecObj2;
//    
//    cout.precision(3);
//    
//    cout<<endl;
//    cout<<fixed<<(myVecProduct.xypVector().at(0))<<endl;
//    cout<<fixed<<(myVecTest.xypVector().at(0))<<endl;
//    cout<<fixed<<(myVecProduct.xypVector().at(1))<<endl;
//    cout<<fixed<<(myVecTest.xypVector().at(1))<<endl;
//    cout<<fixed<<(myVecProduct.xypVector().at(2))<<endl;
//    cout<<fixed<<(myVecTest.xypVector().at(2))<<endl;
//    cout<<endl;
//    
//    CHECK(false);
//}

// the addition assignment operator
TEST_CASE("5.5: The addition assignment += of two Vector2Ds"){
    Vector2D<double> myVecObj1(vector<double> {1,2,3});
    Vector2D<double> myVecObj2(vector<double> {4,5,6});
    Vector2D<double> myVecTest(vector<double> {5,7,9});
    
    myVecObj1+=myVecObj2;
    
    CHECK(myVecObj1 == myVecTest);
}

// the addition assignment operator
TEST_CASE("5.6: The subtraction assignment -= of two Vector2Ds"){
    Vector2D<double> myVecObj1(vector<double> {1,2,3});
    Vector2D<double> myVecObj2(vector<double> {4,5,6});
    Vector2D<double> myVecTest(vector<double> {-3,-3,-3});
    
    myVecObj1-=myVecObj2;
    
    CHECK(myVecObj1 == myVecTest);
}

// the scalar multiple assignment operator
TEST_CASE("5.6: The scalar multiple and assignment *= opperator on a Vector2D"){
    double scale1 = 2;
    double scale2 = -1;
    Vector2D<double> myVecObj(vector<double> {1,2,3});
    Vector2D<double> myVecTest1(vector<double> {2,4,3});
    Vector2D<double> myVecTest2(vector<double> {-2,-4,3});
    
    myVecObj*=scale1;    
    CHECK(myVecObj == myVecTest1);
    myVecObj*=scale2;
    CHECK(myVecObj == myVecTest2);
}

TEST_CASE("5.7: The scalar division and assignment /= opperator on a Vector2D"){
    double scale1 = 2;
    double scale2 = -2;
    Vector2D<double> myVecObj(vector<double> {2,4,3});
    Vector2D<double> myVecTest1(vector<double> {1,2,3});
    Vector2D<double> myVecTest2(vector<double> {-0.5,-1,3});
    
    myVecObj/=scale1;    
    CHECK(myVecObj == myVecTest1);
    myVecObj/=scale2;
    CHECK(myVecObj == myVecTest2);
}


/////////////////////////////////////////////////////////////////////////////////////////////////
// Player Tests

#include "Player.h"

TEST_CASE("1: Test Players are initialised correctly"){
    Vector2D<double> testPosition1;
    Vector2D<double> testPosition2(1,2,3);
    
    Player player1(testPosition1);
    Player player2(testPosition2);
    
    CHECK(player1.getPosition() == testPosition1);
    CHECK(player2.getPosition() == testPosition2);
}

//TEST_CASE("2.1 Test Player is moving Left"){
//    Vector2D<double> position(400,0,0);
//    Vector2D<double> testPlayer1(0,-400,0);
//    Vector2D<double> testPlayer2(0,400,0);
//    Player player1(position);
//    Player player2(position);
//    
//    for(auto i=0;i<100;i++)
//        player1.TestMoveLeft();
//    for(auto i=0;i<100;i++)
//        player2.TestMoveRight();
//    
//    cout<<endl;
//    cout<<player1.getPosition().xypVector().at(0)<<endl;
//    cout<<player1.getPosition().xypVector().at(1)<<endl;
//    cout<<player1.getPosition().xypVector().at(2)<<endl;
//    cout<<endl;
//    cout<<player2.getPosition().xypVector().at(0)<<endl;
//    cout<<player2.getPosition().xypVector().at(1)<<endl;
//    cout<<player2.getPosition().xypVector().at(2)<<endl;
//    cout<<endl;
//    
//    CHECK(player1.getPosition() == testPlayer1);
//    CHECK(player2.getPosition() == testPlayer2);
//}