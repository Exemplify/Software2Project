#ifndef gsc_backEnd_DrawGameObj_H
#define gsc_backEnd_DrawGameObj_H
#include "../FrontEndSystems/GraphicObject.h"
#include "../FrontEndSystems/GameObject.h"
#include "../FrontEndSystems/SpriteInfo.h"
#include "Vector2DConvert.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>


/**
 * @class FailedToLoadTexture
 * @brief Exception used to indicate a texture that does not exist
 */
class FailedToLoadTexture{};
/**
 * @class DrawGameObject
 * @brief Updates the Sprite position and scale for each GameOject
 * @details contains a hash table that stores the individual sprites and corresponding textures for the specific 
 * key provided within the GraphicObject composition of the GameObject. Updates the screen position and scale of the sprite 
 * for each game object provided. If the sprite and texture do not exist inside of the hash table it is created and added into it.
 */
class UpdateGameObjectDisplay
{
public:
	/**
	 * @brief Identifies and applies any changes made to a GameObject and updates a sprite that corresponds to the changes in scale and position of that GameObject
	 * @param GO an std::shared_ptr to the GameObject that is being checked for changes 
	 */
	const sf::Sprite& DetermineGameObjectChanges(shared_ptr<GameObject> GO);
	/**
	 * @brief determines the current size of the hashtable made up of SpriteInfo
	 * @return Returns the size of the hashtable used to store the various SpriteInfo Objects
	 */
	const unsigned int getHashTableSize() const {return _spriteInfoTable.size();}

private:

	std::unordered_map<std::string, std::shared_ptr<SpriteInfo>> _spriteInfoTable; /**< The hashtable used to store the SpriteInfo's for each gameObject*/
	/**
	 * @brief Initialises the Sprite Info that corresponds with the graphic object that is being drawn. Is only called when a SpriteInfo does not exist inside of the hash table
	 * @param graphicObject The GraphicObject which contains the texture location for the corresponding GameObject
	 */
	void InitialiseSpriteInfo(const GraphicObject& graphicObject);

	/**
	 * @brief Updates the sprite properties according to the information from the corresponding GameObject
	 * @param position The updated gamePosition of the GameObject
	 * @param scale The updated scale of the GameObject
	 * @return Returns the sprite object that has been updated with a new position and scale
	 */
	const sf::Sprite& UpdateSpriteProperties(const Vector2D& position, const xyVector& scale, const string& currentObjectKey);
	/**
	 * @brief Checks if the SpriteInfo that corresponds to a particular graphic object has already been generated and is being stored in the hash table
	 * @param correspondingGraphic The Corresponding GraphicObject to the SpriteInfo in the table
	 * @return returns true if the SpriteInfo does Exist
	 */
	bool CheckIfSpriteInfoExists(const GraphicObject& correspondingGraphic);

	
};
#endif