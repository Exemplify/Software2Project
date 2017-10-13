#ifndef SPLASH_H
#define SPLASH_H

#include "GameObject.h"

// Splash Screen object that closes the application on an input and loads the game on an input
// Also displays the background object 

/// requires Seperation of Concerns 
class SplashScreen:public GameObject
{
public:
	SplashScreen(GraphicObject graphicObject, xyVector scale);
	void Update() override;
private:
	// Quits the Game 
	void QuitGame();
	// Loads the main Game Scene
	void PlayGame();
};

#endif 