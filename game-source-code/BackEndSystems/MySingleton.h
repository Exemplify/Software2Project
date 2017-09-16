#ifndef SING_H
#define SING_H

#include <memory>


using std::shared_ptr;

class SingletonExists{};
// Singleton class used to ensure only one instance of specific 
// classes exist at any given time
class MySingleton
{
public:
	static const shared_ptr<MySingleton> getInstance() 
	{
		shared_ptr<MySingleton> thisInstance(Instance);
		return thisInstance;
	}
	MySingleton()
	{
		/* 
		 * Throws an exception if another singleton class is created 
		 * the intention behind this is so that it is obvious when a
		 * second instance is created and can be addressed accordingly 
		*/
		if(instanceExists)
		{
			throw(SingletonExists());
			return;
		}
		else 
		{
			instanceExists = true;
			Instance = this;
		}
	}
	~MySingleton()
	{
		instanceExists = false;
	}
	
protected:
	static bool instanceExists;
	static MySingleton* Instance;
};

#endif
    