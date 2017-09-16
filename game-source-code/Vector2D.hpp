#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <cmath>
#include <vector>

using namespace std;

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
    vector<T> xypVector();
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
    
private:
    // private variables
    T _x_val;
    T _y_val;
    T _radius;
    T _theta;
    T _phi;
    static unsigned int _vectorPrecision;
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