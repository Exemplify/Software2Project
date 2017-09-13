#include "Vector2D.h"

template<class T>
Vector2D<T>::Vector2D(vector<T> cartesianPosition)
{
    if (cartesianPosition.size() != 3)
        throw VectorSizeError{};
    _x_val = cartesianPosition.at(0);
    _y_val = cartesianPosition.at(1);
    _phi = cartesianPosition.at(2);
    
    Vector2D::raduis();
    Vector2D::theta();
}

template<class T>
void Vector2D<T>::raduis()
{
    _radius = sqrt(pow(_x_val,2)+pow(_y_val,2));
}

template<class T>
void Vector2D<T>::theta()
{
    _theta = atan2(_y_val,_x_val);
}

template<class T>
vector<T> Vector2D<T>::xypVector()
{
    vector<T> temp;
    temp.push_back(_x_val);
    temp.push_back(_y_val);
    temp.push_back(_phi);
    return temp;
}

template<class T>
vector<T> Vector2D<T>::rtpVector()
{
    vector<T> temp;
    temp.push_back(_radius);
    temp.push_back(_theta);
    temp.push_back(_phi);
    return temp;
}

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