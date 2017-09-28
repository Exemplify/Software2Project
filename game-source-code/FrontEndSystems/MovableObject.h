#ifndef MOVABLE_OBJECT_H
#define MOVABLE_OBJECT_H

#include "../Vector2D.hpp"

class MovableObject
{
public:
    void moveLeft(Vector2D<double>& position, const double& speed);
    void moveRight(Vector2D<double>& position, const double& speed);
    void moveUp(Vector2D<double>& position, const double& speed);
    void moveDown(Vector2D<double>& position, const double& speed);
    
    void rotateClockwise(Vector2D<double>& position, const double& speed = 0, const Vector2D<double>& centrePoint = Vector2D<double> {0,0,0});
    void rotateAntiClockwise(Vector2D<double>& position, const double& speed = 0, const Vector2D<double>& centrePoint = Vector2D<double> {0,0,0});
    void radialIn(Vector2D<double>& position, const double& speed = 0, const Vector2D<double>& centrePoint = Vector2D<double> {0,0,0});
    void radialOut(Vector2D<double>& position, const double& speed = 0,const Vector2D<double>& centrePoint = Vector2D<double> {0,0,0});
    
private:
    static Vector2D<double> _left_unit;
    static Vector2D<double> _right_unit;
    static Vector2D<double> _up_unit;
    static Vector2D<double> _down_unit;
    static Vector2D<double> _clockwise_unit;
    static Vector2D<double> _anticlockwise_unit;
};

#endif