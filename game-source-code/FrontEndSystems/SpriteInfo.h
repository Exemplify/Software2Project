#ifndef SPR_INF_H
#define SPR_INF_H

#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

struct SpriteInfo
{
	bool isdefined = false;
	std::string textureLocation;
	Vector2f scale{1.0f,1.0f};
	Sprite sprite;
	Texture texture;
};


#endif 