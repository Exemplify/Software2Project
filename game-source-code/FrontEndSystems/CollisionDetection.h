#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../FrontEndSystems/Scene.h"

using namespace sf;
using scene_ptr = std::shared_ptr<Scene>;

class CollisionDetection
{
public:
    CollisionDetection(RenderWindow* dispWindow);
    void initializeCollisionThread();
private:
    RenderWindow* _dispwindow_ptr;
    void runCollisionThread();
    void checkCollisions();
    void checkObjects(shared_ptr<GameObject> gameObj1, shared_ptr<GameObject> gameObj2);
};

#endif