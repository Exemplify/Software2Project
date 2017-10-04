#ifndef SPLASH_H
#define SPLAH_H

#include "GraphicObject.h"

// Splash Screen object that closes the application on an input and loads the game on an input
// Also displays the background object 

/// requires Seperation of Concerns 
class SplashScreen:public GraphicObject
{
public:
	SplashScreen(){}
	void Update() override;
	virtual SplashScreen* Clone() override 
	{return new SplashScreen(*this);}
private:
	// Quits the Game 
	void QuitGame();
	// Loads the main Game Scene
	void PlayGame();
};

#endif 