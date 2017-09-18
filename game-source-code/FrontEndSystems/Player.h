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
    void Update() override;
    
    void TestMoveLeft();
    void TestMoveRight();
private:
    
    void moveLeft();
    void moveRight();
	
    Vector2D<double> _leftUnitVector;
    Vector2D<double> _rightUnitVector;
	double _movespeed = 5;
	
};

#endif