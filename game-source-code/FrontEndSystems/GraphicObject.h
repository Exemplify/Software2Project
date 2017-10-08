#ifndef GRAPHIC_OBJ_H
#define GRAPHIC_OBJ_H
#include <string>


using std::string;

/* Graphic Object:
 * This is the main interface with the display manager, It stores the name of the graphicName which is used as a key 
 * for a hash table inside of the display manager. It also stores the texture location for the current object  
 */
class GraphicObject
{
public:
	GraphicObject():
	_textureLocation{""},
	_graphicName{""}
	{}
	GraphicObject& operator=(const GraphicObject& rhs)
	{
		auto tempObject = new GraphicObject(rhs._textureLocation, rhs._graphicName);
		return *tempObject;
	}

	// Standard constructor used to assign a the texture location of the object and the name of it
	GraphicObject(string textureLocation, string graphicName)
	{
		_textureLocation = textureLocation;
		_graphicName = graphicName;
	}
	
	// returns the graphic Information 
	const string& getGraphicName() const {return _graphicName;}
	const string& getTextureLocation() const {return _textureLocation;}

protected:
	// sprite information required for the display manager
	std::string _textureLocation;
	std::string _graphicName;
};


#endif 