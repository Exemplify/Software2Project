#ifndef DEL_COMP_H
#define DEL_COMP_H

class DelayComponent
{
public:
	DelayComponent(double value, bool immediateUse = false);
	void reduceTime();
	bool DelayFinished();
	void resetDelay();
private:
	double _currentValue;
	double _delayValue; 
	bool _delayFinished;
};

#endif