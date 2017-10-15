#ifndef GAMEOBJ_DATA_ADAPT_H
#define GAMEOBJ_DATA_ADAPT_H
#include "GameData.h"
#include "../Vector2D.h"
#include "../FrontEndSystems/GraphicObject.h"

class GameObjectDataAdaptor
{
public:
	static xyVector ScaleAdaptor(const GameObjectData& data);
	static Vector2D PositionAdaptor(const GameObjectData& data);
	static GraphicObject graphicObjectAdaptor(const GameObjectData& data);
};

#endif 