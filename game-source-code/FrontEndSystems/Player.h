#ifndef PLAYER_H
#define PLAYER_H

#include "GraphicObject.h"
#include "../Vector2D.hpp"
#include <memory>
#include "Character.h"

using namespace std;

class Player : public GraphicObject
{
public:
    Player(Vector2D<double>& startPosition, Character playerStats);
    void Update() override;
    
    void TestMoveLeft();
    void TestMoveRight();
private:
    
    void moveLeft();
    void moveRight();
	void move();
	
    Vector2D<double> _leftUnitVector;
    Vector2D<double> _rightUnitVector;
	Character _playerStats;
	
};

#endif