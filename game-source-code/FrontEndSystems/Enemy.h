#ifndef ENEM_H
#define ENEM_H
#include "GraphicObject.h"
#include "Character.h"

class Enemy: public GraphicObject
{
public:
	Enemy(Character enem):
	_enemyStats{enem}
	{
		_spriteInfo->textureLocation = "resources/AdamHabib.png";
		_spriteInfo->scale = sf::Vector2f{0.25f,0.25f};
	}
	virtual void Start() override; 
	virtual void Update() override;
private:
	void Move();
	void Initialise();
	
	Character _enemyStats;
	void CheckOutsideScreen();
	bool CheckxOutofBounds(double xPos);
	bool CheckyOutofBounds(double yPos);
	
};

#endif 