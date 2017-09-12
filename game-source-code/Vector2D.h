#ifndef VECTOR2D
#define VECTOR2D

#include <cmath>
#include <vector>

using namespace std;

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
    
private:
    // private variables
    T _x_val;
    T _y_val;
    T _radius;
    T _theta;
    T _phi;
    
    //private class functions
    // calculates the radius
    void raduis();
    // calculates theta
    void theta();
};

#endif