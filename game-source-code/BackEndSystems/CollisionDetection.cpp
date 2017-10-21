#include "CollisionDetection.h"
#include "GameManager.h"
#include "../FrontEndSystems/PhysicsObject.h"
#include <mutex>
#include <thread>

CollisionDetection::CollisionDetection(RenderWindow* dispWindow):
_dispwindow_ptr(dispWindow)
{}

void CollisionDetection::InitializeCollisionThread()
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
/**
 * @details It is necesary to iterate through each element and compare it with every other element, each coparison only needs to be done once. This is achieved by 
 * starting from the first element (assuming it is the most left element) it compares itself to all elements to the right of it not including itself. This process is repeated
 * and ensures that no elements are compared with each other more than once, this is done till the element reaches the second last element of the container. It is safe to assume that 
 * each element has already been compared to the last one.
 */
void CollisionDetection::checkCollisions()
{
    auto _activeScene = GameManager::activeScene;
    std::lock_guard<std::mutex> lock(_activeScene->_gameObject_list_mutex);
    auto tempGameObjList = _activeScene->getGameObjectList();

    for(auto idx1 = tempGameObjList.begin(); idx1 != std::prev(tempGameObjList.end()); idx1++)
    {
        for(auto idx2 = ++idx1; idx2 != tempGameObjList.end(); idx2++)
        {
			checkObjects(*idx1, *idx2);
        }
    }
    
}

void CollisionDetection::checkObjects(shared_ptr<GameObject> gameObj1, shared_ptr<GameObject> gameObj2)
{
    if(!gameObj1->isActive() || !gameObj2->isActive() || GameManager::gameClosed())
        return;
	
    auto PhysicsObject1 = std::dynamic_pointer_cast<PhysicsObject>(gameObj1);
    auto PhysicsObject2 = std::dynamic_pointer_cast<PhysicsObject>(gameObj2);
    if (PhysicsObject1 && PhysicsObject2)
    {
        auto magnitudeBetweenObjectPositions = Vector2D::magnitude(PhysicsObject1->getPosition(),PhysicsObject2->getPosition());
        auto collisionBoundary = PhysicsObject1->getSize()+PhysicsObject2->getSize();
        
        if(magnitudeBetweenObjectPositions <= collisionBoundary)
		{
			PhysicsObject1->collisionAction(PhysicsObject2->getType());
			PhysicsObject2->collisionAction(PhysicsObject1->getType());
		}
    }
}