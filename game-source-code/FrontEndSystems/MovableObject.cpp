#include "MovableObject.h"

void MovableObject::moveLeft(Vector2D& position, const double& speed)
{
    position+=(_left_unit*speed);
}

void MovableObject::moveRight(Vector2D& position, const double& speed)
{
    position+=(_right_unit*speed);
}

void MovableObject::moveUp(Vector2D& position, const double& speed)
{
    position+=(_up_unit*speed);
}

void MovableObject::moveDown(Vector2D& position, const double& speed)
{
    position+=(_down_unit*speed);
}

void MovableObject::rotateClockwise(Vector2D& position, const double& speed, const Vector2D& centrePoint)
{
    Vector2D tempClockwise(1,-speed, VectorType::rt);
    position-=centrePoint;
    position*=tempClockwise;
    position+=centrePoint;
}

void MovableObject::rotateAntiClockwise(Vector2D& position, const double& speed, const Vector2D& centrePoint)
{
    Vector2D tempClockwise(1,speed, VectorType::rt);
    position-=centrePoint;
    position*=tempClockwise;
    position+=centrePoint;
}

void MovableObject::radialIn(Vector2D& position, const double& speed, const Vector2D& centrePoint)
{
    position-=centrePoint;
    Vector2D unitVec = position.normalize()*speed;
    position-=unitVec;
    position+=centrePoint;
}

void MovableObject::radialOut(Vector2D& position, const double& speed,const Vector2D& centrePoint)
{
    position-=centrePoint;
    Vector2D unitVec = position.normalize()*speed;
    position+=unitVec;
    position+=centrePoint;
}


Vector2D MovableObject::_left_unit{-1,0};

Vector2D MovableObject::_right_unit{1,0};

Vector2D MovableObject::_up_unit{0,1};

Vector2D MovableObject::_down_unit{0,-1};

Vector2D MovableObject::_anticlockwise_unit{1,0.01};

Vector2D MovableObject::_clockwise_unit{1,-0.01};
