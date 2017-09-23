#ifndef GRAPHIC_OBJ_H
#define GRAPHIC_OBJ_H
#include "SpriteInfo.h"
#include "GameObject.h"

class GraphicObject : public GameObject
{
public:
	GraphicObject(std::shared_ptr<SpriteInfo> spriteInfo):
	GameObject(),
	_spriteInfo{spriteInfo}
	{}
	GraphicObject():
	GameObject(),
	_spriteInfo{new SpriteInfo()}
	{}
	std::shared_ptr<SpriteInfo> getSpriteInfo() const
	{
		return _spriteInfo; 
	}
	virtual ~GraphicObject(){}
protected:
	std::shared_ptr<SpriteInfo>  _spriteInfo;
};


#endif 