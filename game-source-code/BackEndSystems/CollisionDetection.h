#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../FrontEndSystems/Scene.h"

class CollisionDetection
{
public:
    CollisionDetection(sf::RenderWindow* dispWindow);
    void InitializeCollisionThread();
private:
    sf::RenderWindow* _dispwindow_ptr;
    void runCollisionThread();
    void checkCollisions();
    void checkObjects(std::shared_ptr<GameObject> gameObj1, std::shared_ptr<GameObject> gameObj2);
};

#endif