#ifndef SPR_INF_H
#define SPR_INF_H

#include <string>
#include <SFML/Graphics.hpp>

class DisplayManager;

class SpriteInfo
{
	friend class DisplayManager;
public:
	std::string spritekey;
	bool isdefined = false;
	std::string textureLocation;
private:
	sf::Sprite sprite;
};


#endif 