#ifndef SPR_INF_H
#define SPR_INF_H

#include <string>
#include <SFML/Graphics.hpp>
/**
 * @class SpriteInfo
 * @brief The Sprite information that is stored in the hashtable for the presentation layer
 */
struct SpriteInfo
{
	sf::Sprite sprite; /**<sfml sprite object only used in the presentation layer*/
	sf::Texture texture; /**<sfml texture object only used in the presentation layer*/
};


#endif 