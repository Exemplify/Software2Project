#ifndef MOVABLE_OBJECT_H
#define MOVABLE_OBJECT_H

#include "../Vector2D.h"

class MovableObject
{
public:
    void moveLeft(Vector2D& position, const double& speed);
    void moveRight(Vector2D& position, const double& speed);
    void moveUp(Vector2D& position, const double& speed);
    void moveDown(Vector2D& position, const double& speed);
    
    void rotateClockwise(Vector2D& position, const double& speed = 0, const Vector2D& centrePoint = Vector2D {0,0});
    void rotateAntiClockwise(Vector2D& position, const double& speed = 0, const Vector2D& centrePoint = Vector2D {0,0});
    void radialIn(Vector2D& position, const double& speed = 0, const Vector2D& centrePoint = Vector2D {0,0});
    void radialOut(Vector2D& position, const double& speed = 0,const Vector2D& centrePoint = Vector2D {0,0});
    
private:
    static Vector2D _left_unit;
    static Vector2D _right_unit;
    static Vector2D _up_unit;
    static Vector2D _down_unit;
    static Vector2D _clockwise_unit;
    static Vector2D _anticlockwise_unit;
};

#endif