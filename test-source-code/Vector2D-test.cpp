#include "doctest.h"
#include <iostream>
#include <cmath>
#include "../game-source-code/Vector2D.hpp"

//===============================================================================================
//Section 1
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

//===============================================================================================
//Section 2
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

//===============================================================================================
//Section 3
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

//===============================================================================================
//Section 4
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

//===============================================================================================
//Section 5
// Other operator overloads defined and tested

// the addition operator
// rtp form requires individual approximation
TEST_CASE("5.1: The addition + of two Vector2Ds (in rtp declared form)"){
    Vector2D<double> myVecObj1(vector<double> {1,M_PI/8,3}, VectorType::rtp);
    Vector2D<double> myVecObj2(vector<double> {1,(5*M_PI/8),6}, VectorType::rtp);
    vector<double> vecTest {sqrt(2),(3*M_PI/8),9};
    
    Vector2D<double> addedVec = myVecObj1+myVecObj2;
    
    CHECK(doctest::Approx(addedVec.rtpVector().at(0)) == vecTest.at(0));
    CHECK(doctest::Approx(addedVec.rtpVector().at(1)) == vecTest.at(1));
    CHECK(doctest::Approx(addedVec.rtpVector().at(2)) == vecTest.at(2));
}

// the addition operator
// xyp form can be directly equated
TEST_CASE("5.2: The addition + of two Vector2Ds (in xyp declared form)"){
    Vector2D<double> myVecObj1(vector<double> {1,2,3});
    Vector2D<double> myVecObj2(vector<double> {4,5,6});
    Vector2D<double> myVecTest(vector<double> {5,7,9});
    
    Vector2D<double> addedVec = myVecObj1+myVecObj2;
    
    CHECK(addedVec == myVecTest);
}

// the subtraction operator
// rtp form requires individual approximation
TEST_CASE("5.3: The subtraction - of two Vector2Ds (in rtp declared form)"){
    Vector2D<double> myVecObj1(vector<double> {1,M_PI/8,3}, VectorType::rtp);
    Vector2D<double> myVecObj2(vector<double> {1,(5*M_PI/8),6}, VectorType::rtp);
    vector<double> vecTest {sqrt(2),(-M_PI/8),-3};
    
    Vector2D<double> subtractedVec = myVecObj1-myVecObj2;
    
    CHECK(doctest::Approx(subtractedVec.rtpVector().at(0)) == vecTest.at(0));
    CHECK(doctest::Approx(subtractedVec.rtpVector().at(1)) == vecTest.at(1));
    CHECK(doctest::Approx(subtractedVec.rtpVector().at(2)) == vecTest.at(2));
}

// the subtraction operator
// xyp form can be directly equated
TEST_CASE("5.4: The subtraction - of two Vector2Ds (in xyp declared form)"){
    Vector2D<double> myVecObj1(vector<double> {4,5,6});
    Vector2D<double> myVecObj2(vector<double> {1,2,3});
    Vector2D<double> myVecTest(vector<double> {3,3,3});
    
    Vector2D<double> subtractedVec = myVecObj1-myVecObj2;
    
    CHECK(subtractedVec == myVecTest);
}

//the Vector2D multiply operator
// rtp form can be directly equated
TEST_CASE("5.5: The Vector2D multiply * of two Vector2Ds (in rtp declared form)"){
    Vector2D<double> myVecObj1(vector<double> {2,1,3}, VectorType::rtp);
    Vector2D<double> myVecObj2(vector<double> {3,2,1}, VectorType::rtp);
    Vector2D<double> myVecTest(vector<double> {6,3,0}, VectorType::rtp);
    
    CHECK((myVecObj1*myVecObj2) == myVecTest);
}


//the Vector2D multiply operator
// xyp form requires individual approximation
TEST_CASE("5.6: The Vector2D multiply * of two Vector2Ds (in xyp declared form)"){
    Vector2D<double> myVecObj1(vector<double> {1,2,3});
    Vector2D<double> myVecObj2(vector<double> {4,5,6});
    vector<double> myVecTest {-6,13,0};
    
    Vector2D<double> myVecProduct = myVecObj1*myVecObj2;
    
    CHECK(doctest::Approx(myVecProduct.xypVector().at(0)) == myVecTest.at(0));
    CHECK(doctest::Approx(myVecProduct.xypVector().at(1)) == myVecTest.at(1));
    CHECK(doctest::Approx(myVecProduct.xypVector().at(2)) == myVecTest.at(2));
}

//the Vector2D scalar multiply operator
// rtp form can be directly equated
TEST_CASE("5.7: The scalar multiply * of a Vector2D (in rtp declared form)"){
    Vector2D<double> myVec(vector<double> {2,1,4}, VectorType::rtp);
    Vector2D<double> vecTest (vector<double> {-4*M_PI,1,0}, VectorType::rtp);
    double scalar = -2*M_PI;
    
    Vector2D<double> vecProd = myVec*scalar;
    CHECK(vecProd == vecTest);
}

//the Vector2D scalar multiply operator
// xyp form requires individual approximation
TEST_CASE("5.8: The scalar multiply * of a Vector2D (in xyp declared form)"){
    Vector2D<double> myVec (vector<double> {1,2,3});
    vector<double> vecTest {-M_PI,-2*M_PI,0};
    double scalar = -M_PI;
    
    Vector2D<double> vecProd = myVec*scalar;
    
    CHECK(doctest::Approx(vecProd.xypVector().at(0)) == vecTest.at(0));
    CHECK(doctest::Approx(vecProd.xypVector().at(1)) == vecTest.at(1));
    CHECK(doctest::Approx(vecProd.xypVector().at(2)) == vecTest.at(2));
}

//the Vector2D scalar division operator
// rtp form can be directly equated
TEST_CASE("5.9: The scalar division / of a Vector2D (in rtp declared form)"){
    Vector2D<double> myVec(vector<double> {2*M_PI,1,4}, VectorType::rtp);
    Vector2D<double> vecTest (vector<double> {-2,1,0}, VectorType::rtp);
    double scalar = -M_PI;
    
    Vector2D<double> vecProd = myVec/scalar;
    CHECK(vecProd == vecTest);
}

//the Vector2D scalar multiply operator
// xyp form requires individual approximation
TEST_CASE("5.10: The scalar division / of a Vector2D (in xyp declared form)"){
    Vector2D<double> myVec (vector<double> {M_PI,2*M_PI,3});
    vector<double> vecTest {-1,-2,0};
    double scalar = -M_PI;
    
    Vector2D<double> vecProd = myVec/scalar;
    
    CHECK(doctest::Approx(vecProd.xypVector().at(0)) == vecTest.at(0));
    CHECK(doctest::Approx(vecProd.xypVector().at(1)) == vecTest.at(1));
    CHECK(doctest::Approx(vecProd.xypVector().at(2)) == vecTest.at(2));
}


// the addition assignment operator
// rtp form requires individual approximation
TEST_CASE("5.11: The addition assignment += of two Vector2Ds (in rtp declared form)"){
    Vector2D<double> myVecObj1(vector<double> {1,M_PI/8,3}, VectorType::rtp);
    Vector2D<double> myVecObj2(vector<double> {1,(5*M_PI/8),6}, VectorType::rtp);
    vector<double>  vecTest {sqrt(2),(3*M_PI/8),9};
    
    myVecObj1+=myVecObj2;
    
    CHECK(doctest::Approx(myVecObj1.rtpVector().at(0)) == vecTest.at(0));
    CHECK(doctest::Approx(myVecObj1.rtpVector().at(1)) == vecTest.at(1));
    CHECK(doctest::Approx(myVecObj1.rtpVector().at(2)) == vecTest.at(2));
}

// the addition assignment operator
// xyp form can be directly equated
TEST_CASE("5.12: The addition assignment += of two Vector2Ds (in xyp declared form)"){
    Vector2D<double> myVecObj1(vector<double> {1,2,3});
    Vector2D<double> myVecObj2(vector<double> {4,5,6});
    Vector2D<double> myVecTest(vector<double> {5,7,9});
    
    myVecObj1+=myVecObj2;
    
    CHECK(myVecObj1 == myVecTest);
}

// the subtraction assignment operator
// rtp form requires individual approximation
TEST_CASE("5.11: The subtraction assignment -= of two Vector2Ds (in rtp declared form)"){
    Vector2D<double> myVecObj1(vector<double> {1,M_PI/8,3}, VectorType::rtp);
    Vector2D<double> myVecObj2(vector<double> {1,(5*M_PI/8),6}, VectorType::rtp);
    vector<double> vecTest {sqrt(2),(-M_PI/8),-3};
    
    myVecObj1-=myVecObj2;
    
    CHECK(doctest::Approx(myVecObj1.rtpVector().at(0)) == vecTest.at(0));
    CHECK(doctest::Approx(myVecObj1.rtpVector().at(1)) == vecTest.at(1));
    CHECK(doctest::Approx(myVecObj1.rtpVector().at(2)) == vecTest.at(2));
}

// the addition assignment operator
// xyp form can be directly equated
TEST_CASE("5.12: The addition assignment -= of two Vector2Ds (in xyp declared form)"){
    Vector2D<double> myVecObj1(vector<double> {4,5,6});
    Vector2D<double> myVecObj2(vector<double> {1,2,3});
    Vector2D<double> myVecTest(vector<double> {3,3,3});
    
    myVecObj1-=myVecObj2;
    
    CHECK(myVecObj1 == myVecTest);
}

// the scalar multiple assignment operator
// rtp form can be directly equated
TEST_CASE("5.13: The scalar multiple and assignment *= opperator on a Vector2D (in rtp declared form)"){
    Vector2D<double> myVec(vector<double> {2,1,3}, VectorType::rtp);
    Vector2D<double> vecTest (vector<double> {-4*M_PI,1,3}, VectorType::rtp);
    double scalar = -2*M_PI;
    
    myVec*=scalar;
    CHECK(myVec == vecTest);

}

// the scalar multiple assignment operator
// rtp form can be directly equated
TEST_CASE("5.14: The scalar multiple and assignment *= opperator on a Vector2D (in xyp declared form)"){
    Vector2D<double> myVec (vector<double> {1,2,3});
    vector<double> vecTest {-2*M_PI,-4*M_PI,3};
    double scalar = -2*M_PI;
    
    myVec*=scalar;
    
    CHECK(doctest::Approx(myVec.xypVector().at(0)) == vecTest.at(0));
    CHECK(doctest::Approx(myVec.xypVector().at(1)) == vecTest.at(1));
    CHECK(doctest::Approx(myVec.xypVector().at(2)) == vecTest.at(2));

}

// the scalar division assignment operator
// rtp form can be directly equated
TEST_CASE("5.15: The scalar division and assignment /= opperator on a Vector2D (in rtp declared form)"){
    Vector2D<double> myVec(vector<double> {2*M_PI,1,4}, VectorType::rtp);
    Vector2D<double> vecTest (vector<double> {-2,1,4}, VectorType::rtp);
    double scalar = -M_PI;
    
    myVec/=scalar;
    CHECK(myVec == vecTest);

}

// the scalar division assignment operator
// rtp form can be directly equated
TEST_CASE("5.16: The scalar division and assignment /= opperator on a Vector2D (in xyp declared form)"){
    Vector2D<double> myVec (vector<double> {M_PI,2*M_PI,3});
    vector<double> vecTest {-1,-2,3};
    double scalar = -M_PI;
    
    myVec/=scalar;
    
    CHECK(doctest::Approx(myVec.xypVector().at(0)) == vecTest.at(0));
    CHECK(doctest::Approx(myVec.xypVector().at(1)) == vecTest.at(1));
    CHECK(doctest::Approx(myVec.xypVector().at(2)) == vecTest.at(2));
    
}

//===============================================================================================
//Section 6
// Nocmalised vector function TEST_CASE

TEST_CASE("6.1: A Vector2D can be normalized (in rtp declated form)"){
    Vector2D<double> myVec(5,M_PI/8,1, VectorType::rtp);
    Vector2D<double> vecTest(1,M_PI/8,0, VectorType::rtp);
    Vector2D<double> normVec = myVec.normalize();
    
    CHECK(normVec == vecTest);
}

TEST_CASE("6.1: A Vector2D can be normalized (in xyp declated form)"){
    Vector2D<double> myVec(-1,2,1);
    Vector2D<double> vecTest(1,atan2(2,-1),0, VectorType::rtp);
    Vector2D<double> normVec = myVec.normalize();
    
    CHECK(normVec == vecTest);
}