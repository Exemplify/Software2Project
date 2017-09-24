#ifndef SPLASH_H
#define SPLAH_H

#include "GraphicObject.h"

class SplashScreen:public GraphicObject
{
public:
	SplashScreen(){}
	void Update() override;
private:
	void QuitGame();
	void PlayGame();
};
// happy with this class in its entirety

#endif 