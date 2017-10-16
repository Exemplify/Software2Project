#include "GameObjectDataAdaptor.h"

xyVector GameObjectDataAdaptor::ScaleAdaptor(const GameObjectData& data)
{
	return xyVector(data.scaleX, data.scaleY);
}
Vector2D GameObjectDataAdaptor::PositionAdaptor(const GameObjectData& data)
{
	return Vector2D(data.PosX, data.PosY);
}
GraphicObject GameObjectDataAdaptor::graphicObjectAdaptor(const GameObjectData& data)
{
	return GraphicObject(data.graphic_location, data.graphic_name);
}
