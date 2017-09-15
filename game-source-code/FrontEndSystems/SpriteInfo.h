#ifndef SPR_INF_H
#define SPR_INF_H

#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

struct SpriteInfo
{
	bool isdefined = false;
	string textureLocation;
	Sprite sprite;
	Texture texture;
};


#endif 