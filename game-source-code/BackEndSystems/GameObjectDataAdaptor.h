#ifndef GAMEOBJ_DATA_ADAPT_H
#define GAMEOBJ_DATA_ADAPT_H
#include "GameData.h"
#include "../Vector2D.h"
#include "../FrontEndSystems/GraphicObject.h"
/**
 * @class GameObjectDataAdaptor
 * @brief Static class used to covert GameObjectData into the parameters required to construct a GameObject
 */
class GameObjectDataAdaptor
{
public:
	/**
	 * @brief Converts GameObjectData into a xyVector for the GameObjects scale
	 * @param data The GameObjectData that is converted
	 * @return Returns the xyVector for the GameObjects scale
	 */
	static xyVector ScaleAdaptor(const GameObjectData& data);
	/**
	 * @brief Converts GameObjectData into a Vector2D for the GameObjects position
	 * @param data The GameObjectData that is converted
	 * @return Returns the Vector2D for the GameObjects position
	 */
	static Vector2D PositionAdaptor(const GameObjectData& data);
	/**
	 * @brief Converts GameObjectData into a GraphicObject for the GameObjects graphicObject composition
	 * @param data The GameObjectData that is converted
	 * @return Returns the constructed GraphicObject from the provided data
	 */
	static GraphicObject graphicObjectAdaptor(const GameObjectData& data);
};

#endif 