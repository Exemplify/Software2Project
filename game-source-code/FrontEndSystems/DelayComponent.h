#ifndef DEL_COMP_H
#define DEL_COMP_H

class DelayComponent
{
public:
	DelayComponent(){}
	DelayComponent(double value, bool immediateUse = false);
    // why is the immediateUse flag necessary?
    
	void reduceTime();
	bool DelayFinished();
	void resetDelay();
private:
	double _currentValue;
    // is there a more intuitive/ descriptive name for the above variable?
	double _delayValue; 
	bool _delayFinished;
};

#endif