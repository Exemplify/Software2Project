#ifndef SPLASH_H
#define SPLAH_H

#include "GraphicObject.h"

class SplashScreen:public GraphicObject
{
public:
	SplashScreen(){}
	void Update() override;
	virtual SplashScreen* Clone() override 
	{return new SplashScreen(*this);}
private:
	void QuitGame();
	void PlayGame();
};

#endif 