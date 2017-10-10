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

	if(CheckIfSpriteInfoExists(*graphicObject))
	{
		InitialiseSpriteInfo(*graphicObject);
	}
	
	return UpdateSpriteProperties(GO->getPosition(), GO->getScale());

}

const sf::Sprite& UpdateGameObjectDisplay::UpdateSpriteProperties(const Vector2D<double>& position, const xyVector& scale, SpriteInfo)
{
	// obtains the relative sfml screen position
	auto currentSpriteInfoHash = _spriteInfoTable.find(currentObjectKey);
	auto screenPosition = Vector2DConvert::Vector2DtoScreenPosition(position);

	// sets the position and scale of the sprite accordingly
	auto currentSpriteData = currentSpriteInfoHash->second;
	currentSpriteData->sprite.setPosition(screenPosition);

	currentSpriteData->sprite.setScale(sf::Vector2f(scale.x, scale.y));
	return currentSpriteData->sprite;
}


bool UpdateGameObjectDisplay::CheckIfSpriteInfoExists(const GraphicObject& correspondingGraphic)
{
	auto currentObjectKey = correspondingGraphic.getGraphicName();
	auto currentSpriteInfoHash = _spriteInfoTable.find(currentObjectKey);
	// Checks if the objects sprite information has already been defined
	return (currentSpriteInfoHash == _spriteInfoTable.end())
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
		_spriteInfoTable.insert({gameObjectKey, newSpriteInfo});
	}
}