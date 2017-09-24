#include "movement.h"

void movement::moveLeft(Player Object1)
{
    Object1._position+=(_left_unit*Object1._speed);
    
}

void movement::moveRight(Player Object1)
{
    Object1._position+=(_right_unit*Object1._speed);
}

void movement::moveUp(Player Object1)
{
    Object1._position+=(_up_unit*Object1._speed);
}

void movement::moveDown(Player Object1)
{
    Object1._position+=(_down_unit*Object1._speed);
}

void movement::rotateAntiClockwise(Player Object1)
{
    Object1._position*=_anticlockwise_unit;
}

void movement::rotateClockwise(Player Object1)
{
    Object1._position*=_clockwise_unit;
}

void movement::radialIn(Player Object1)
{
    Vector2D<double> temp = ((Object1._position).normalize())/(Object1._speed);
    Object1._position-=temp;
}

void movement::radialOut(Player Object1)
{
    Vector2D<double> temp = ((Object1._position).normalize())/(Object1._speed);
    Object1._position+=temp;
}


Vector2D<double> movement::_left_unit{-1,0,0};
Vector2D<double> movement::_right_unit{1,0,0};
Vector2D<double> movement::_up_unit{0,1,0};
Vector2D<double> movement::_down_unit{0,-1,0};

Vector2D<double> movement::_anticlockwise_unit{1,0.01,0};
Vector2D<double> movement::_clockwise_unit{1,-0.01,0};