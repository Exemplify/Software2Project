#ifndef GRAPHIC_OBJ_H
#define GRAPHIC_OBJ_H
#include <string>


using std::string;

 /**
  * @class GraphicObject
  * @brief  This is the Utility class with the display manager, It stores the name of the object and location of the image file which are 
  * both necessary for the DisplayManager to correctly display the specified image. 
  * @details The Graphic Object has a tight coupling with the Presentation layer classes. The graphic name of the object is used as a key within a hashtable 
  * to identify the specific sfml sprite and texture that needs to be drawn for the corresponding object. GraphicObject acts as a link between the Presentation Layer and the 
  * Domain layer. It forms a composition relationship with the GameObject class. A NullObject is assigned by default for derived implimentations of GameObject that do not require a GraphicObject
  * The NullObject consistis of a NullObject.png image which is a single transparent pixel and the graphicName Null. This is an Object name that is preserved by the constructor. 
  * ie another GraphicObject may not have the name Null.
  */
class GraphicObject
{
public:
	GraphicObject();
	GraphicObject& operator=(const GraphicObject& rhs);
	GraphicObject(string textureLocation, string graphicName);
	
	/**
	 * @brief Getter is necessary to decouple the presentation layer from the game logic layer.
	 * @return Returns a constant string that represents the graphic name of the object
	 */
	const string& getGraphicName() const {return _graphicName;}
	/**
	 * @brief Getter is necessary to decouple the presentation layer from the game logic layer.
	 * @return Returns a constant string that represents the location of the image file that is being used
	 */
	const string& getTextureLocation() const {return _textureLocation;}
	const static GraphicObject NullGraphic;
	virtual ~GraphicObject() = default;

protected:
	std::string _textureLocation; /**<The location of the Image that the object represents*/ 
	std::string _graphicName; /**<The name used to load objects specified by the texture location*/ 
};



#endif 