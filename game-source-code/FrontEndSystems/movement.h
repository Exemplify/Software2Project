#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Vector2D.hpp"
#include "Player.h"

class Player;

class movement
{
public:
    
    static void moveLeft(Player Object1);
    static void moveRight(Player Object1);
    static void moveUp(Player Object1);
    static void moveDown(Player Object1);
    
    static void rotateClockwise(Player Object1);
    static void rotateClockwise(Player Object1, Vector2D<double> centrePoint);
    static void rotateClockwise(Player Object1, Player Object2);
    
    static void rotateAntiClockwise(Player Object1);
    static void rotateAntiClockwise(Player Object1, Vector2D<double> centrePoint);
    static void rotateAntiClockwise(Player Object1, Player Object2);
    
    static void radialIn(Player Object1);
    static void radialIn(Player Object1, Vector2D<double> centrePoint);
    static void radialIn(Player Object1, Player Object2);
    
    static void radialOut(Player Object1);
    static void radialOut(Player Object1, Vector2D<double> centrePoint);
    static void radialOut(Player Object1, Player Object2);
    
private:
    static Vector2D<double> _left_unit;
    static Vector2D<double> _right_unit;
    static Vector2D<double> _up_unit;
    static Vector2D<double> _down_unit;
    static Vector2D<double> _clockwise_unit;
    static Vector2D<double> _anticlockwise_unit;
};

#endif