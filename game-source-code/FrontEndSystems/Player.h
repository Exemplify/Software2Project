#ifndef PLAYER_H
#define PLAYER_H

#include "GraphicObject.h"
#include "../Vector2D.hpp"
#include <memory>

using namespace std;

class Player : public GraphicObject
{
public:
    Player(Vector2D<double>& startPosition);
    void moveLeft();
    void moveRight();
    
private:
    double _speed;
};

#endif