#ifndef GRAPHIC_OBJ_H
#define GRAPHIC_OBJ_H

#include "GameObject.h"
#include "SpriteInfo.h"
#include <memory>

class GraphicObject : public GameObject
{
public:
	GraphicObject(): 
	_spriteInfo(new SpriteInfo())
	{}
	bool HasGraphic() override { return true; }
	std::shared_ptr<SpriteInfo> getSpriteInfo() 
	{
		return _spriteInfo; 
	}
protected:
	std::shared_ptr<SpriteInfo>  _spriteInfo;
};


#endif 