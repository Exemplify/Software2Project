#ifndef GRAPHIC_OBJ_H
#define GRAPHIC_OBJ_H
#include "SpriteInfo.h"
#include "GameObject.h"

/// Requires the copy constructor and an assignment opperator overload
/// Requires decoupling from sfml 
/* Graphic Object
 * This is the main interface with the display manager, the sprite information stored inside of this
 * class. Only graphic objects and derivatives of graphic objects are used by the displayManager class 
 */
 
class GraphicObject : public GameObject
{
public:
	// Graphic object requires a SpriteInfo as an invariance
	GraphicObject(std::shared_ptr<SpriteInfo> spriteInfo):
	GameObject(),
	_spriteInfo{spriteInfo}
	{}
	/// Default constructor should be removed, only purpose is for testing
	GraphicObject():
	GameObject(),
	_spriteInfo{new SpriteInfo()}
	{}
	// returns the sprite information 
	std::shared_ptr<SpriteInfo> getSpriteInfo() const
	{
		return _spriteInfo; 
	}
	/// Clone Function still in development maybe needs to be removed 
	virtual GraphicObject* Clone() override
	{return new GraphicObject(*this);}
	
	// virtual destructor
	virtual ~GraphicObject(){}
protected:
	// sprite information required for the display manager
	std::shared_ptr<SpriteInfo>  _spriteInfo;
};


#endif 