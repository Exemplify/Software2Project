#ifndef VECTOR2D
#define VECTOR2D

#include <cmath>
#include <vector>

using namespace std;

class VectorSizeError {};

template<class T>
class Vector2D
{
public:
    // Constructor
    Vector2D(vector<T> cartesianPosition);
    // cartesian position function
    vector<T> xypVector();
    // polar position function
    vector<T> rtpVector();
    // overload operator == defined
    bool operator ==(const Vector2D<T>& rhs) const;
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

#endif