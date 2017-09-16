#include "BackEndSystems/GameManager.h"
#include <memory>
#include <iostream>
#include "FrontEndSystems/Scene.h"
#include "FrontEndSystems/GraphicObject.h"
#include "FrontEndSystems/SpriteInfo.h"
#include "BackEndSystems/Input.h"

using std::shared_ptr;
shared_ptr<Scene> SplashScreen();

int main()
{
	shared_ptr<Scene> splashScene =  SplashScreen();
	GameManager gm;
	gm.AddScene(splashScene);
	gm.GameLoop();
	return EXIT_SUCCESS;
}

shared_ptr<Scene> SplashScreen()
{
	shared_ptr<Scene> splashScene{new Scene()};
	shared_ptr<GraphicObject> background{new GraphicObject()};
	shared_ptr<SpriteInfo> backgroundInfo =  background->getSpriteInfo();
	backgroundInfo->textureLocation = "resources/PlayerShield.png";
	splashScene->Instantiate(background);
	background->setActive(true);
	return splashScene;
}

