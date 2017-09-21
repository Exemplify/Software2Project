#include "Vector2D.hpp"

// Default Constructor
template<class T>
Vector2D<T>::Vector2D()
{
    *this = _origin;
}

// Scalar Constructor
template<class T>
Vector2D<T>::Vector2D(T val1, T val2, T phi, const VectorType& vectype)
{
    if (vectype == VectorType::xyp)
    {
        _x_val = val1;
        _y_val = val2;
        _phi = phi;
        radius();
        theta();
    }
    else if (vectype == VectorType::rtp)
    {
        _radius = val1;
        _theta = val2;
        _phi = phi;
        xVal();
        yVal();
        theta();
    }
}
// Vector Constructor
template<class T>
Vector2D<T>::Vector2D(const vector<T>& vec, const VectorType& vectype)
{
    if(vec.size()!=3)
        throw VectorSizeError();
    if(vectype == VectorType::xyp)
    {
        _x_val = vec.at(0);
        _y_val = vec.at(1);
        _phi = vec.at(2);
        radius();
        theta();
    }
    else if(vectype == VectorType::rtp)
    {
        _radius = vec.at(0);
        _theta = vec.at(1);
        _phi = vec.at(2);
        xVal();
        yVal();
        theta();
    }
}

// Copy Constructor
template<class T>
Vector2D<T>::Vector2D(const Vector2D<T>& rhs)
{
    *this = rhs;
}

//private calculate radius
template<class T>
void Vector2D<T>::radius()
{
    _radius = sqrt(pow(_x_val,2)+pow(_y_val,2));
}

//private calculate theta
template<class T>
void Vector2D<T>::theta()
{
    _theta = atan2(_y_val,_x_val);
}

//private calculate x
template<class T>
void Vector2D<T>::xVal()
{
    _x_val = _radius*cos(_theta);
}

//private calculate y
template<class T>
void Vector2D<T>::yVal()
{
    _y_val = _radius*sin(_theta);
}

// return the Vector2D as a vector<T> in cartesian form
template<class T>
vector<T> Vector2D<T>::xypVector()
{
    vector<T> temp;
    temp.push_back(_x_val);
    temp.push_back(_y_val);
    temp.push_back(_phi);
    return temp;
}

//return the Vector2D as a vector<T> in polar form
template<class T>
vector<T> Vector2D<T>::rtpVector()
{
    vector<T> temp;
    temp.push_back(_radius);
    temp.push_back(_theta);
    temp.push_back(_phi);
    return temp;
}

//overload operators
// equivalancy operator, Vector2D == Vector2d
template<class T>
bool Vector2D<T>::operator==(const Vector2D<T>& rhs) const
{
    if(_x_val != rhs._x_val)
        return false;
    if(_y_val != rhs._y_val)
        return false;
    if(_phi != rhs._phi)
        return false;
    return true;
}

// addition and create operator: newVector2D = Vector2D + Vector2D
template<class T>
Vector2D<T> Vector2D<T>::operator + (const Vector2D<T>& rhs) const
{
    T x = _x_val + rhs._x_val;
    T y = _y_val + rhs._y_val;
    T phi = _phi + rhs._phi;
    Vector2D<T> temp(x,y,phi);
    return temp;
}

// subtraction and create operator: newVector2D = Vector2D - Vector2D
template<class T>
Vector2D<T> Vector2D<T>::operator - (const Vector2D<T>& rhs) const
{
    T x = _x_val - rhs._x_val;
    T y = _y_val - rhs._y_val;
    T phi = _phi - rhs._phi;
    Vector2D<T> temp(x,y,phi);
    return temp;
}

// Vector multiply and create operator: newVector2D = Vector2D * Vector2D
template<class T>
Vector2D<T> Vector2D<T>::operator * (const Vector2D<T>& rhs) const
{
    T r = _radius*rhs._radius;
    T t = _theta+rhs._theta;
    T phi = 0;
    Vector2D<T> temp(r,t,phi, VectorType::rtp);
    return temp;
}

// scalar multiply and create operator: newVector2D = Vector2D * scalar
template<class T>
Vector2D<T> Vector2D<T>::operator * (const T& scalar) const
{
    T r = _radius*scalar;
    T t = _theta;
    T phi = 0;
    Vector2D<T> temp(r,t,phi, VectorType::rtp);
    return temp;
}

// scalar division and create operator: newVector2D = Vector2D / scalar
template<class T>
Vector2D<T> Vector2D<T>::operator / (const T& scalar) const
{
    T r = _radius/scalar;
    T t = _theta;
    T phi = 0;
    Vector2D<T> temp(r,t,phi, VectorType::rtp);
    return temp;
}

// addition assignment operator: thisVector2d = thisVector2D + Vector2D
template<class T>
Vector2D<T>& Vector2D<T>::operator += (const Vector2D<T>& rhs)
{
    _x_val += rhs._x_val;
    _y_val += rhs._y_val;
    _phi += rhs._phi;
    radius();
    theta();
    return *this;
}

// subtraction assignment operator: thisVector2D = thisVector2D - Vector2D
template<class T>
Vector2D<T>& Vector2D<T>::operator -= (const Vector2D<T>& rhs)
{
    _x_val -= rhs._x_val;
    _y_val -= rhs._y_val;
    _phi -= rhs._phi;
    radius();
    theta();
    return *this;
}

// Vector multiply assignemnt operator: thisVector2D = thisVector2D*Vector2D
template<class T>
Vector2D<T>& Vector2D<T>::operator *= (const Vector2D<T>& rhs)
{
    _radius *= rhs._radius;
    _theta += rhs._theta;
    _phi += rhs._phi;
    xVal();
    yVal();
    theta();
    return *this;
}

// scalar multiply assignment operator: thisVector2D = thisVector2D*scalar
template<class T>
Vector2D<T>& Vector2D<T>::operator *= (const T scale)
{
    _radius *= scale;
    xVal();
    yVal();
    return *this;
}

// scalar division assignment operator: thisVector2D = thisVector2D/scalar
template<class T>
Vector2D<T>& Vector2D<T>::operator /= (const T scale)
{
    _radius /= scale;
    xVal();
    yVal();
    return *this;
}

// default single input magnitude function
template<class T>
T Vector2D<T>::magnitude(const Vector2D<T>& lhs)
{
    return magnitude(lhs, _origin); // also could return _raduis
}


// magnttude between two vectors
template<class T>
T Vector2D<T>::magnitude(const Vector2D<T>& lhs, const Vector2D<T>& rhs)
{
    T dx = lhs._x_val-rhs._x_val;
    T dy = lhs._y_val-rhs._y_val;
    T temp = sqrt(pow(dx,2)+pow(dy,2));
    return temp;
}

template<class T>
Vector2D<T> Vector2D<T>::_origin{0,0,0};

template<class T>
Vector2D<T> Vector2D<T>::normalize() const
{
    Vector2D<T> temp(_radius/_radius, _theta, _phi - _phi, VectorType::rtp);
    return temp;
}