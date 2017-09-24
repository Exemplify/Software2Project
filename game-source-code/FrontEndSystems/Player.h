#ifndef PLAYER_H
#define PLAYER_H

#include "GraphicObject.h"
#include "../Vector2D.hpp"
#include <memory>
#include "Character.h"
#include "DelayComponent.h"
#include "ShootComponent.h"

using namespace std;

class Player : public GraphicObject
{
    friend class movement;
public:
    Player(Vector2D<double>& startPosition, Character playerStats, std::shared_ptr<SpriteInfo> bulletSprite);
	
    void Update() override;
    
    void TestMoveLeft();
    void TestMoveRight();
private:
	void move();
	
    Vector2D<double> _leftUnitVector;
    Vector2D<double> _rightUnitVector;
    double _speed;
	// Composition Variables 
	Character _playerStats;
	DelayComponent _shootDelay;
	ShootComponent _shootComp;
	void ShootConditionalCheck();
	
};

#endif