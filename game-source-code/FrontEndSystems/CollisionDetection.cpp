#include "CollisionDetection.h"
#include "../BackEndSystems/GameManager.h"
#include "PhysicsObject.h"
#include <mutex>
#include <thread>

CollisionDetection::CollisionDetection(RenderWindow* dispWindow):
_dispwindow_ptr(dispWindow)
{}

void CollisionDetection::initializeCollisionThread()
{
    std::thread collisionThread(&CollisionDetection::runCollisionThread, this);
    collisionThread.detach();
}

void CollisionDetection::runCollisionThread()
{
    while(_dispwindow_ptr->isOpen())
    {
        checkCollisions();
    }
}

void CollisionDetection::checkCollisions()
{
    auto _activeScene = GameManager::activeScene;
    std::lock_guard<std::mutex> lock(_activeScene->_gameObj_list_mutex);
    auto tempGameObjList = _activeScene->getGameObjectList();
//    vector<std::shared_ptr<PhysicsObject>> physObj_prtVec;
//    transform(tempGameObjList.begin(), tempGameObjList.end(), physObj_ptrVec.begin(), std::dynamic_pointer_cast<PhysicsObject>);
    for(auto gameObj1 : tempGameObjList)
    {
        for(auto gameObj2 : tempGameObjList)
        {
            if(gameObj1 == gameObj2)
                continue;
            else
                checkObjects(gameObj1, gameObj2);
        }
    }
    
}

void CollisionDetection::checkObjects(shared_ptr<GameObject> gameObj1, shared_ptr<GameObject> gameObj2)
{
    if(!gameObj1->isActive() || !gameObj2->isActive())
        return;
        
    auto PhysicsObject1 = std::dynamic_pointer_cast<PhysicsObject>(gameObj1);
    auto PhysicsObject2 = std::dynamic_pointer_cast<PhysicsObject>(gameObj2);
    if (PhysicsObject1 && PhysicsObject2)
    {
        auto magnitudeBetweenObjectPositions = Vector2D<double>::magnitude(PhysicsObject1->getPosition(),PhysicsObject2->getPosition());
        auto collisionBoundary = PhysicsObject1->getSize()+PhysicsObject2->getSize();
        
        if(magnitudeBetweenObjectPositions <= collisionBoundary)
            PhysicsObject1->collisionAction(PhysicsObject2->getType());
    }
}