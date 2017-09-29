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
 */	  
enum class VectorType
{
    xyp = 1,
    rtp
};
class VectorSizeError {};

template<class T>
class Vector2D
{
public:
    // Default Constructor
    Vector2D<T>();
    // Scalar Constructor
    Vector2D<T>(T val1, T val2, T phi, const VectorType& vectype = VectorType::xyp);
    // Vector Constructor
    Vector2D<T>(const vector<T>& vec, const VectorType& vectype = VectorType::xyp);
    // Copy constructor
    Vector2D(const Vector2D<T>& rhs);
    // cartesian position function
    vector<T> xypVector() const;
    // polar position function
    vector<T> rtpVector();
    
    // overload operators defined
    // equivalancy operator, Vector2D == Vector2d
    bool operator ==(const Vector2D<T>& rhs) const;
    // addition and create operator: newVector2D = Vector2D + Vector2D
    Vector2D<T> operator + (const Vector2D<T>& rhs) const;
    // subtraction and create operator: newVector2D = Vector2D - Vector2D
    Vector2D<T> operator - (const Vector2D<T>& rhs) const;
    // Vector multiply and create operator: newVector2D = Vector2D * Vector2D
    Vector2D<T> operator * (const Vector2D<T>& rhs) const;
    // scalar multiply and create operator: newVector2D = Vector2D * scalar
    Vector2D<T> operator * (const T& scalar) const;
    // scalar division and create operator: newVector2D = Vector2D / scalar
    Vector2D<T> operator / (const T& scalar) const;
    // addition assignment operator: thisVector2d = thisVector2D + Vector2D
    Vector2D<T>& operator += (const Vector2D<T>& rhs);
    // subtraction assignment operator: thisVector2D = thisVector2D - Vector2D
    Vector2D<T>& operator -= (const Vector2D<T>& rhs);
    // Vector multiply assignemnt operator: thisVector2D = thisVector2D*Vector2D
    Vector2D<T>& operator *= (const Vector2D<T>& rhs);
    // scalar multiply assignment operator: thisVector2D = thisVector2D*scalar
    Vector2D<T>& operator *= (const T scale);
    // scalar division assignment operator: thisVector2D = thisVector2D/scalar
    Vector2D<T>& operator /= (const T scale);
    
    // magnitude function
    static T magnitude(const Vector2D<T>& lhs);
    static T magnitude(const Vector2D<T>& lhs, const Vector2D<T>& rhs);
    
    // normalize function
    Vector2D<T> normalize() const;
    
private:
    // private variables
    T _x_val;
    T _y_val;
    T _radius;
    T _theta;
    T _phi;
    //static variable Vector2D _origin
    static Vector2D<T> _origin;
    
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

#include "Vector2D.tpp"

#endif