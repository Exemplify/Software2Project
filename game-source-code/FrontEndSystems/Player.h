#ifndef PLAYER_H
#define PLAYER_H

#include "PhysicsObject.h"
#include "../Vector2D.hpp"
#include <memory>
#include "Character.h"
#include "DelayComponent.h"
#include "ShootComponent.h"
#include "GraphicObject.h"

using namespace std;
/// Character rework required here as well 

/* Player Description
 * Player is used to contain the responsibilities of the user as they play the game. 
 * The class has the responsibilities of moving shooting all based off of input from the user. 
 * The player also detects when it has collided with either the enemy or the enemy bullets
 */
class Player : public PhysicsObject
{
public:
	/// Redundant constructors need to be reworked 
	Player()
	{
		_type = GameObjectType::player;
	}
	Player(Vector2D<double>& startPosition, Character playerStats);
    Player(Vector2D<double>& startPosition, Character playerStats, std::shared_ptr<GraphicObject> bulletGraphic);
	/// Clone still in development
	virtual Player* Clone() override 
	{return new Player(*this);}
	// override functions called by external objects
    void Update() override;
    virtual void collisionAction(GameObjectType objectType) override;
	// returns the graphic object contained within the player
	const std::shared_ptr<GraphicObject> getGraphicObject()  override
	{return _graphicObject;}
	
private:
	// moves the player in the specified direction
	void move();
	
	// Composition Variables 
	/// character needs to be adjusted and the additional components pushed into it
	Character _playerStats;
	std::shared_ptr<GraphicObject> _graphicObject;
	DelayComponent _shootDelay;
	ShootComponent _shootComp;
	// Checks if the conditions for shooting have been met, delay is over and shoot input is pressed
	void ShootConditionalCheck();
	
	
};

#endif