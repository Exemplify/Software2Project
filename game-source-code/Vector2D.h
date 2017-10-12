#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <cmath>
#include <vector>

using namespace std;
  
enum class VectorType
{
    xy = 1,
    rt
};
class VectorSizeError {};

struct xyVector
{
	xyVector() {};
	xyVector(double X, double Y):
	x{X},
	y{Y}
	{}
    double x;
    double y;
};
struct rtVector
{
	rtVector()
	{}
	rtVector(double R, double T):
	r{R},
	t{T}
	{}
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