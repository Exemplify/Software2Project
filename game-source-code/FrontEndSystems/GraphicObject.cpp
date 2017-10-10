#include "GraphicObject.h"


/**
 * @class GraphicNameReservedfooNullGraphic
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

/**
 * @brief Copy Constructor of GraphicObject
 */
GraphicObject::GraphicObject(const GraphicObject& copy)
{
	_textureLocation = copy._textureLocation;
	_graphicName = copy._graphicName;
}
/**
 * @brief Standard Constructor, creates a Graphic Object with the client specified parameters
 * @param textureLocation The texture location for the image that the object uses
 * @param graphicName The name of that corresponds to objects that use the same image
 * @details Checks if the reserved graphicName "Null" is used, throws GraphicNameReservedforNullGraphic if Null is used
 */
GraphicObject::GraphicObject(string textureLocation, string graphicName):
_textureLocation{textureLocation},
_graphicName{graphicName}
{
	if(_graphicName == "Null" && _textureLocation != "resources/NullGraphic.png")
		throw(GraphicNameReservedforNullGraphic());
}
/**
 * @brief Assignment operator overload
 */
GraphicObject& GraphicObject::operator=(const GraphicObject& rhs)
{
	_textureLocation = rhs._textureLocation;
	_graphicName = rhs._graphicName;
	return *this;
}

