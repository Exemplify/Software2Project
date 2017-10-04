#include "MovableObject.h"

void MovableObject::moveLeft(Vector2D<double>& position, const double& speed)
{
    position+=(_left_unit*speed);
}

void MovableObject::moveRight(Vector2D<double>& position, const double& speed)
{
    position+=(_right_unit*speed);
}

void MovableObject::moveUp(Vector2D<double>& position, const double& speed)
{
    position+=(_up_unit*speed);
}

void MovableObject::moveDown(Vector2D<double>& position, const double& speed)
{
    position+=(_down_unit*speed);
}

void MovableObject::rotateClockwise(Vector2D<double>& position, const double& speed, const Vector2D<double>& centrePoint)
{
    Vector2D<double> tempClockwise(1,-speed,0,VectorType::rtp);
    position-=centrePoint;
    position*=tempClockwise;
    position+=centrePoint;
}

void MovableObject::rotateAntiClockwise(Vector2D<double>& position, const double& speed, const Vector2D<double>& centrePoint)
{
    Vector2D<double> tempClockwise(1,speed,0,VectorType::rtp);
    position-=centrePoint;
    position*=tempClockwise;
    position+=centrePoint;
}

void MovableObject::radialIn(Vector2D<double>& position, const double& speed, const Vector2D<double>& centrePoint)
{
    position-=centrePoint;
    Vector2D<double> unitVec = position.normalize()*speed;
    position-=unitVec;
    position+=centrePoint;
}

void MovableObject::radialOut(Vector2D<double>& position, const double& speed,const Vector2D<double>& centrePoint)
{
    position-=centrePoint;
    Vector2D<double> unitVec = position.normalize()*speed;
    position+=unitVec;
    position+=centrePoint;
}


Vector2D<double> MovableObject::_left_unit{-1,0,0};

Vector2D<double> MovableObject::_right_unit{1,0,0};

Vector2D<double> MovableObject::_up_unit{0,1,0};

Vector2D<double> MovableObject::_down_unit{0,-1,0};

Vector2D<double> MovableObject::_anticlockwise_unit{1,0.01,0};

Vector2D<double> MovableObject::_clockwise_unit{1,-0.01,0};