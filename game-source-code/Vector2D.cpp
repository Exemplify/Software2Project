#include "Vector2D.h"

// Default Constructor
Vector2D::Vector2D()
{
    *this = _origin;
}

// Scalar Constructor
Vector2D::Vector2D(double val1, double val2, const VectorType& vectype)
{
    if (vectype == VectorType::xy)
    {
        _xyvec.x = val1;
        _xyvec.y = val2;
        radius();
        theta();
    }
    else if (vectype == VectorType::rt)
    {
        _rtvec.r = val1;
        _rtvec.t = val2;
        xVal();
        yVal();
        theta();
    }
}

// Vector Constructor for xyVector
Vector2D::Vector2D(const xyVector vec)
{
    _xyvec = vec;
    radius();
    theta();
}

// Vector Constructor for rtVector
Vector2D::Vector2D(const rtVector vec)
{
    _rtvec = vec;
    xVal();
    yVal();
}

// Copy Constructor
Vector2D::Vector2D(const Vector2D& rhs)
{
    *this = rhs;
}

//private calculate radius
void Vector2D::radius()
{
    _rtvec.r = sqrt(pow(_xyvec.x,2)+pow(_xyvec.y,2));
}

//private calculate theta
void Vector2D::theta()
{
    _rtvec.t = atan2(_xyvec.y,_xyvec.x);
}

//private calculate x
void Vector2D::xVal()
{
    _xyvec.x = (_rtvec.r)*cos(_rtvec.t);
}

//private calculate y
void Vector2D::yVal()
{
    _xyvec.y = _rtvec.r*sin(_rtvec.t);
}

// return the Vector2D as a xyVector struct (cartesian form)
xyVector Vector2D::getXYVector() const
{
    return _xyvec;
}

//return the Vector2D as a rtVector struct (polar form)
rtVector Vector2D::getRTVector() const
{
    return _rtvec;
}

//overload operators
// assignment operator, Vector2D = Vector2D
Vector2D& Vector2D::operator = (const Vector2D& rhs)
{
    _xyvec = rhs._xyvec;
    _rtvec = rhs._rtvec;
    return *this;
}

// equivalancy operator, Vector2D == Vector2D
bool Vector2D::operator==(const Vector2D& rhs) const
{
    if (magnitude(*this,rhs)>magnitude_tolerance)
        return false;
    return true;
}

// addition and create operator: newVector2D = Vector2D + Vector2D
Vector2D Vector2D::operator + (const Vector2D& rhs) const
{
    double x = _xyvec.x + rhs._xyvec.x;
    double y = _xyvec.y + rhs._xyvec.y;
    Vector2D temp(x,y);
    return temp;
}

// subtraction and create operator: newVector2D = Vector2D - Vector2D
Vector2D Vector2D::operator - (const Vector2D& rhs) const
{
    double x = _xyvec.x - rhs._xyvec.x;
    double y = _xyvec.y - rhs._xyvec.y;
    Vector2D temp(x,y);
    return temp;
}

// Vector multiply and create operator: newVector2D = Vector2D * Vector2D
Vector2D Vector2D::operator * (const Vector2D& rhs) const
{
    double r = _rtvec.r*rhs._rtvec.r;
    double t = _rtvec.t+rhs._rtvec.t;
    Vector2D temp(r,t, VectorType::rt);
    return temp;
}

// scalar multiply and create operator: newVector2D = Vector2D * scalar
Vector2D Vector2D::operator * (const double& scalar) const
{
    double r = _rtvec.r*scalar;
    double t = _rtvec.t;
    Vector2D temp(r,t, VectorType::rt);
    return temp;
}

// scalar division and create operator: newVector2D = Vector2D / scalar
Vector2D Vector2D::operator / (const double& scalar) const
{
    double r = _rtvec.r/scalar;
    double t = _rtvec.t;
    Vector2D temp(r,t, VectorType::rt);
    return temp;
}

// addition assignment operator: thisVector2d = thisVector2D + Vector2D
Vector2D& Vector2D::operator += (const Vector2D& rhs)
{
    _xyvec.x += rhs._xyvec.x;
    _xyvec.y += rhs._xyvec.y;
    radius();
    theta();
    return *this;
}

// subtraction assignment operator: thisVector2D = thisVector2D - Vector2D
Vector2D& Vector2D::operator -= (const Vector2D& rhs)
{
    _xyvec.x -= rhs._xyvec.x;
    _xyvec.y -= rhs._xyvec.y;
    radius();
    theta();
    return *this;
}

// Vector multiply assignemnt operator: thisVector2D = thisVector2D*Vector2D
Vector2D& Vector2D::operator *= (const Vector2D& rhs)
{
    _rtvec.r *= rhs._rtvec.r;
    _rtvec.t += rhs._rtvec.t;
    xVal();
    yVal();
    theta();
    return *this;
}

// scalar multiply assignment operator: thisVector2D = thisVector2D*scalar
Vector2D& Vector2D::operator *= (const double scale)
{
    _rtvec.r *= scale;
    xVal();
    yVal();
    return *this;
}

// scalar division assignment operator: thisVector2D = thisVector2D/scalar
Vector2D& Vector2D::operator /= (const double scale)
{
    _rtvec.r /= scale;
    xVal();
    yVal();
    return *this;
}

// default single input magnitude function
double Vector2D::magnitude(const Vector2D& lhs)
{
    return magnitude(lhs, _origin); // also could return _raduis
}


// magnttude between two vectors
double Vector2D::magnitude(const Vector2D& lhs, const Vector2D& rhs)
{
    double dx = lhs._xyvec.x-rhs._xyvec.x;
    double dy = lhs._xyvec.y-rhs._xyvec.y;
    double temp = sqrt(pow(dx,2)+pow(dy,2));
    return temp;
}

Vector2D Vector2D::_origin{0,0};
double Vector2D::magnitude_tolerance = 0.000000001;

Vector2D Vector2D::normalize() const
{
    Vector2D temp(_rtvec.r/_rtvec.r, _rtvec.t, VectorType::rt);
    return temp;
}