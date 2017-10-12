#ifndef SING_H
#define SING_H

#include <memory>


using std::shared_ptr;

// Singleton class used to ensure only one instance of specific 
// classes exist at any given time
template<class T>
class Singleton
{
public:
	
	virtual static std::shared_ptr<T> getInstance();
	{
		if(!_instanceExists)
		{
			instanceExists = true;
			_Instance = std::make_shared<>();
		}
		
		return _Instance;
	}
	virtual ~MySingleton()
private:

	bool checkForInstance()
	{
		if(instanceExists)
		{
			return true;
		}
		else 
		{
			instanceExists = true;
			Instance = this;
			return false;
		}
	}
	
	static bool instanceExists;
	static std::shared_ptr<T> Instance;
};

#endif
    