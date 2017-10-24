#include "GraphicObject.h"


/**
 * @class GraphicNameReservedforNullGraphic
 * @brief Exception thrown when the client attempts to create an object with the same _graphicName as the NullGraphics
 */
class GraphicNameReservedforNullGraphic{};

/**
 * @brief NullGraphic Declaration, requires the "NullGraphic.png" image to be available
 */
const GraphicObject GraphicObject::NullGraphic{"resources/NullGraphic.png", "Null"};

/**
 * @brief Default Constructor, creates a NullGraphic by default
 */
GraphicObject::GraphicObject()
{
	*this = NullGraphic;
}


GraphicObject::GraphicObject(string textureLocation, string graphicName):
_textureLocation{textureLocation},
_graphicName{graphicName}
{
	if(_graphicName == "Null" && _textureLocation != "resources/NullGraphic.png")
		throw(GraphicNameReservedforNullGraphic());
}
