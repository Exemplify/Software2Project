#ifndef LASER_GEN_H
#define LASER_GEN_H
#include "GameObject.h"
#include "Application.h"
#include <vector>
const int MAX_NUM_FIELD_OBJECTS = 5;
const int MAX_NUM_GENERATORS = 2;
class LaserGeneratorContainer : public GameObject
{
public:
	LaserGeneratorContainer(LaserGenerator generator1, LaserGenerator generator2, std::vector<std::shared_ptr<GameObject>> laserObjects);
	void Start()
	{
		for(auto& laserObject : _laserObjects)
		{
			
		}
//		auto laserGenerator1 = std::dynamic_pointer_cast<LaserGenerator>(
//							Application::getGameRepository()->getGameObjectbyTypeDuringRuntime(GameObjectType::laserGenerator));
//		auto laserGenerator2 = std::dynamic_pointer_cast<LaserGenerator>(
//							Application::getGameRepository()->getGameObjectbyTypeDuringRuntime(GameObjectType::laserGenerator));
//		for(auto x = 0; x < MAX_NUM_FIELD_OBJECTS; x++)
//		{
//			auto laserObject = Application::getGameRepository()->getGameObjectbyTypeDuringRuntime(GameObjectType::laserGenerator));
//			laserObjects.push_back(laserObject);
//		}
	}
	void LaserGeneratorDestroyed()
	{
		if(_numberOfGeneratorsDestroyed >= MAX_NUM_GENERATORS-1)
		{ 
			Destroy();
			return;
		}
		
		_numberOfGeneratorsDestroyed++;
		for(auto& laserObject : _laserObjects)
		{
			laserObject->Destroy();
		}
	}
	
private:
	std::vector<std::shared_ptr<GameObject>> _laserObjects;
	std::shared_ptr<LaserGenerator> _laserGenerator1;
	std::shared_ptr<LaserGenerator> _laserGenerator2;
	
	unsigned int _numberOfGeneratorsDestroyed = 0;
	
}

#endif
