#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <cmath>
#include <vector>

using namespace std;

class VectorSizeError {};

template<class T>
class Vector2D
{
public:
    // Default Constructor
    Vector2D<T>();
    // Constructor
    Vector2D(vector<T> cartesianPosition);
    // Copy constructor
    Vector2D(const Vector2D<T>& rhs);
    // cartesian position function
    vector<T> xypVector();
    // polar position function
    vector<T> rtpVector();
    // overload operator == defined
    bool operator ==(const Vector2D<T>& rhs) const;
    Vector2D<T> operator + (const Vector2D<T>& rhs);
    Vector2D<T> operator - (const Vector2D<T>& rhs);
    Vector2D<T>& operator += (const Vector2D<T>& rhs);
    Vector2D<T>& operator -= (const Vector2D<T>& rhs);
    Vector2D<T>& operator *= (const T scale);
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
    //static variable Vector2D _origin
    static Vector2D<T> _origin;
    
    //private class functions
    // calculates the radius
    void raduis();
    // calculates theta
    void theta();
};

#include "Vector2D.tpp"

#endif