#ifndef SCENE_FAC_H
#define SCENE_FAC_H
#include "../FrontEndSystems/Scene.h"
#include "../FrontEndSystems/GameObject.h"
#include "DatabaseInterface.h"
#include <list>
#include <memory>
/**
 * @class SceneFactory
 * @brief Base class used to create the various scenes within the game
 */
class SceneFactory
{
public:
	/**
	 * @brief Constructs the Scene defined by the type of Scene factory 
	 * @param database The DatabaseInterface that contains the information about the various GameObjects
	 * @return Returns the Constructed Scene
	 */
	std::shared_ptr<Scene> getScene(std::shared_ptr<DatabaseInterface> database) const;
protected:
	/**
	 * @brief Returns the gameObject list required for the construction of the specific Scene
	 * @param database The DatabaseInterface that contains the information about the various GameObjects
	 */
	virtual std::list<std::shared_ptr<GameObject>> getGameObectList(std::shared_ptr<DatabaseInterface> database) const = 0;
};

#endif 