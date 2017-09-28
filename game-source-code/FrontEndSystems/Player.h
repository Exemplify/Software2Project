#ifndef PLAYER_H
#define PLAYER_H

#include "PhysicsObject.h"
#include "../Vector2D.hpp"
#include <memory>
#include "Character.h"
#include "DelayComponent.h"
#include "ShootComponent.h"

using namespace std;

class Player : public PhysicsObject
{
public:
	Player()
	{
		_type = GameObjectType::player;
	}
	Player(Vector2D<double>& startPosition, Character playerStats);
    Player(Vector2D<double>& startPosition, Character playerStats, std::shared_ptr<SpriteInfo> bulletSprite);
	virtual Player* Clone() override 
	{return new Player(*this);}
    void Update() override;
    virtual void collisionAction(GameObjectType objectType) override;
private:
	void move();
	
	// Composition Variables 
	Character _playerStats;
	DelayComponent _shootDelay;
	ShootComponent _shootComp;
	void ShootConditionalCheck();
	
};

#endif