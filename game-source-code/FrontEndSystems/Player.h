#ifndef PLAYER_H
#define PLAYER_H

#include "GraphicObject.h"
#include "../Vector2D.hpp"
#include <memory>
#include "Character.h"
#include "DelayComponent.h"

using namespace std;

class Player : public GraphicObject
{
public:
    Player(Vector2D<double>& startPosition, Character playerStats);
	
    void Update() override;
    
    void TestMoveLeft();
    void TestMoveRight();
private:
	void move();
	
    Vector2D<double> _leftUnitVector;
    Vector2D<double> _rightUnitVector;
	// Composition Variables 
	Character _playerStats;
	DelayComponent _shootDelay;
	
	void Shoot();
	void ShootConditionalCheck();
	
};

#endif