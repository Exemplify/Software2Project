#ifndef gsc_backEnd_DrawGameObj_H
#define gsc_backEnd_DrawGameObj_H
/**
 * @class DrawGameObject
 * @brief Draws Each GameObject and its corresponding graphic to the display window.
 * @details contains a hash table that stores the individual sprites and corresponding textures for the specific 
 * key provided within the GraphicObject composition of the GameObject.
 */
class DrawGameObject
{
public:
/**
 * @brief Draws the corresponding Sprite of the GameObject provided the the display window at the corresponding screen position
 * @param GO
 */
	void DrawSpriteFromGameObject(shared_ptr<GameObject> GO);
private:
	std::shared_ptr<SpriteInfo>& InitialiseGraphicObject(const GraphicObject& graphicObject, std::string gameObjectKey);
	
};
#endif