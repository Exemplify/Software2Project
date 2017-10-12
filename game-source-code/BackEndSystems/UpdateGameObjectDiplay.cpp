#include "UpdateGameObjectDisplay.h"
#include <string>




/**
 * @details Initially Identifies if the GameObject's corresponding sprite has been drawn before.
 * If it does not exist a texture is created according to the information stored inside of the GraphicObject 
 * Composition and the sprite is setup accordingly. After which the sprite is updated to the corresponding scale and position of the GameObject
 */
const sf::Sprite& UpdateGameObjectDisplay::DetermineGameObjectChanges(std::shared_ptr<GameObject> GO)
{

		
	auto graphicObject = GO->getGraphicObject();

	if(!CheckIfSpriteInfoExists(graphicObject))
	{
		InitialiseSpriteInfo(graphicObject);
	}
	
	return UpdateSpriteProperties(GO->getPosition(), GO->getScale(), graphicObject.getGraphicName());
}

/**
 * @details Updates the position of the sprite ,retrieved from the hash table, to the corresponding screen position by converting the
 * GameOject's game position to the corresponding screen position and then assigns the scale of the object to sprite
 */
const sf::Sprite& UpdateGameObjectDisplay::UpdateSpriteProperties(const Vector2D<double>& position, const xyVector& scale, const string& currentObjectKey)
{
	// obtains the relative sfml screen position
	auto currentSpriteInfoHash = _spriteInfoTable.find(currentObjectKey);
	auto screenPosition = Vector2DConvert::ConvertVector2DtoScreenPosition(position);

	// sets the position and scale of the sprite accordingly
	auto currentSpriteData = currentSpriteInfoHash->second;
	currentSpriteData->sprite.setPosition(screenPosition);

	currentSpriteData->sprite.setScale(sf::Vector2f(scale.x, scale.y));
	return currentSpriteData->sprite;
}

/**
 * @details Determines whether the SpriteInfo object that corresponds to the key obtained from the graphic object exists.
 * Uses std::find to check for the object and returns a true if the iterator returned is not equal to the end of the hash table
 */
bool UpdateGameObjectDisplay::CheckIfSpriteInfoExists(const GraphicObject& correspondingGraphic)
{
	auto currentObjectKey = correspondingGraphic.getGraphicName();
	auto spriteInfoIdx = _spriteInfoTable.find(currentObjectKey);
	// Checks if the objects sprite information has already been defined
	return (spriteInfoIdx != _spriteInfoTable.end());
}


void UpdateGameObjectDisplay::InitialiseSpriteInfo(const GraphicObject& graphicObject)
{
	
	auto newSpriteInfo = std::make_shared<SpriteInfo>();
	// declarations for the spriteInfo components to improve readability
	auto& texture = newSpriteInfo->texture;
	auto& texture_location = graphicObject.getTextureLocation();
	// if the texture does not exist then an exception is thrown
	if(!texture.loadFromFile(texture_location))
	{
		throw(FailedToLoadTexture());
	}
	else
	{
		// sets the current texture to the sprite
		newSpriteInfo->sprite.setTexture(newSpriteInfo->texture);
		
		// Obtains the bounds of the sprite so that the position can be set to
		// the sprites centre as this is more desirable for this project
		auto bounds = newSpriteInfo->sprite.getGlobalBounds();
		auto newOrigin = Vector2f((bounds.width/2),(bounds.height/2));
		
		// Defines the new origin, at the centre of the sprite
		newSpriteInfo->sprite.setOrigin(newOrigin);
		
		// Adds the Created spriteInfo to the unordered map
		auto key = graphicObject.getGraphicName();
		_spriteInfoTable.insert({key, newSpriteInfo});
	}
}