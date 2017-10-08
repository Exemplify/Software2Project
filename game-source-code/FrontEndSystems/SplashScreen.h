#ifndef SPLASH_H
#define SPLAH_H

#include "GameObject.h"

// Splash Screen object that closes the application on an input and loads the game on an input
// Also displays the background object 

/// requires Seperation of Concerns 
class SplashScreen:public GameObject
{
public:
	SplashScreen(std::shared_ptr<GraphicObject> graphicObject, xyVector scale);
	void Update() override;
	virtual SplashScreen* Clone() override 
	{return new SplashScreen(*this);}
	const std::shared_ptr<GraphicObject> getGraphicObject() override
	{return _graphicObject;}
private:
	std::shared_ptr<GraphicObject> _graphicObject;
	// Quits the Game 
	void QuitGame();
	// Loads the main Game Scene
	void PlayGame();
};

#endif 