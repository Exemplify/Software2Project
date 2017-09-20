#ifndef GRAPHIC_OBJ_H
#define GRAPHIC_OBJ_H

#include "GameObject.h"
#include "SpriteInfo.h"
#include <memory>

class GraphicObject : public GameObject
{
public:
	GraphicObject(std::shared_ptr<SpriteInfo> spriteInfo):
	_spriteInfo(spriteInfo)
	{}
	GraphicObject():
	_spriteInfo(new SpriteInfo())
	{}
	bool HasGraphic() override { return true; }
	std::shared_ptr<SpriteInfo> getSpriteInfo() const
	{
		return _spriteInfo; 
	}
protected:
	std::shared_ptr<SpriteInfo>  _spriteInfo;
};


#endif 