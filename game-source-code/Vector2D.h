#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <cmath>
#include <vector>

using namespace std;
/* General Thoughts:
 * Overall a good implementation for this type of class however i personally feel that the interface is lacking.
 * Mainly in the following areas, the use of std vector feels redundant and unintuative as well as the phi aspect for the class. It doesnt feel like
 * it belongs in this type of class it is only relivant when an object is visible and doesnt particularly feel like it fits in with the functionality 
 * that this class offers. As an example adding a vector to a vector will inherantly change a vectors position but that doesnt mean it needs to rotate. 
 * the rotation for the object would be seperate in my opinion as its not really implicit in what a vector space represents mathimatically,.
 * The std vector class feels very redundant as it is unintuative and makes accessing information quite difficult. I feel that it would be better to either use a VectorInfo 
 * struct or make the variable setters and getters, this is an interface class we want to operate on the variables in multiple ways sometimes individually sometimes not. 
 * The struct would improve this additionall by allowing us to return the struct only we would achieve the readibility improvements expressed bellow:
 * 
 * this is just a basic example where we increase out x component by 10 each time
 * 
 * Current implementation:
 * 	auto myVec = MyVector2D.xypVector();
 * 	myVec.at(0) += 10;
 *  MyVector2D = Vector2D<Type>(myVec, VectorType::xyp);
 * 
 * Struct Implementation:
 * 	template<class T>
 * 	struct VectorInfo
 * 	{
 * 		T x, y, p , theta, radius;
 * 	};
 * 
 * 	auto myVec = MyVector2D.getVectorInfo();
 * 	myVect.x += 10;
 *  MyVector2D = Vector2D<Type>(myVec);
 * 
 * Setter and Getter Implementation
 * 	enum class VectorInfo
 * 	{
 * 		 x, y, p , theta, radius;
 * 	};
 * 	
 * 	auto x = MyVector2D.getVal(VectorInfo::x);
 * 	x+=10;
 * 	MyVector2D.setVal(Vectorinfo::x);
 * 
 * I feel like a reasign funtion would also be useful so that you dont have to make a new vector each time the object is changed.
 * 	
 * 	I know this can also be done through the use of creating and adding vectors together but sometimes it is more 
 *  intuative to pull the information and then add it individually and personally i feel like that is easy to understand and makes the code more readible 
 * 
 * the last comment i want to make is on the Templating, I feel that this is completely redundant and needs to be removed firstly a vector is by default numerical 
 * the template allows it to be of any type and this class has an invariance that is numerical only. It can just be a double as both ints and floats can be represented by 
 * a double through a cast. Additionally the way it stands breaks that invariance I can make a Vector<CollisionDetection> myVec;
 * this will break in the default constructor as it will try to assign 0 0 0 to the object. Templating is meant for generic objects of any type like the vector it is just a list
 * and performs list operations but it never tries to assign the values to the object itself, it just holds the information. 
 * 
 * Edit: 
 * In the Lecture you missed due to the doctors appointment levit mentioned that using a strcut to hold the data is a good idea as it is a purely utility object and is used to pass
 * information states around, so we could have a 
 * struct xyVector
 * {
 * 		double x, y; 
 * };
 * struct trVector
 * {
 * 		double t, r; 
 * };
 * 
 * 
 */	  
enum class VectorType
{
    xy = 1,
    rt
};
class VectorSizeError {};

struct xyVector
{
    double x;
    double y;
};
struct rtVector
{
    double r;
    double t;
};

class Vector2D
{
public:
    // Default Constructor
    Vector2D();
    // Scalar Constructor
    Vector2D(double val1, double val2, const VectorType& vectype = VectorType::xy);
    // Vector Constructor for xyVector
    Vector2D(const xyVector vec);
    // Vector Constructor for rtVector
    Vector2D(const rtVector vec);
    // Copy constructor
    Vector2D(const Vector2D& rhs);
    // cartesian position function
    xyVector getXYVector() const;
    // polar position function
    rtVector getRTVector() const;
    
    // overload operators defined
    // assignment operator, Vector2D = Vector2D
    Vector2D& operator = (const Vector2D& rhs); 
    // equivalancy operator, Vector2D == Vector2D
    bool operator ==(const Vector2D& rhs) const;
    // addition and create operator: newVector2D = Vector2D + Vector2D
    Vector2D operator + (const Vector2D& rhs) const;
    // subtraction and create operator: newVector2D = Vector2D - Vector2D
    Vector2D operator - (const Vector2D& rhs) const;
    // Vector multiply and create operator: newVector2D = Vector2D * Vector2D
    Vector2D operator * (const Vector2D& rhs) const;
    // scalar multiply and create operator: newVector2D = Vector2D * scalar
    Vector2D operator * (const double& scalar) const;
    // scalar division and create operator: newVector2D = Vector2D / scalar
    Vector2D operator / (const double& scalar) const;
    // addition assignment operator: thisVector2d = thisVector2D + Vector2D
    Vector2D& operator += (const Vector2D& rhs);
    // subtraction assignment operator: thisVector2D = thisVector2D - Vector2D
    Vector2D& operator -= (const Vector2D& rhs);
    // Vector multiply assignemnt operator: thisVector2D = thisVector2D*Vector2D
    Vector2D& operator *= (const Vector2D& rhs);
    // scalar multiply assignment operator: thisVector2D = thisVector2D*scalar
    Vector2D& operator *= (const double scale);
    // scalar division assignment operator: thisVector2D = thisVector2D/scalar
    Vector2D& operator /= (const double scale);
    
    // magnitude function
    static double magnitude(const Vector2D& lhs);
    static double magnitude(const Vector2D& lhs, const Vector2D& rhs);
    
    // normalize function
    Vector2D normalize() const;
    
private:
    //private variables
    xyVector _xyvec;
    rtVector _rtvec;
    
    //static variable Vector2D _origin
    static Vector2D _origin;
    static double magnitude_tolerance;
    
    //private class functions
    // calculates radius
    void radius();
    // calculates theta
    void theta();
    // calculates x
    void xVal();
    // calculates y
    void yVal();
};

#endif