#include "BackEndSystems/GameManager.h"
#include <memory>
#include <iostream>
#include "FrontEndSystems/Scene.h"
#include "FrontEndSystems/SplashScreen.h"
#include "FrontEndSystems/SpriteInfo.h"
#include "BackEndSystems/Input.h"

using std::shared_ptr;
shared_ptr<Scene> SplashScreenFunc();

int main()
{
	shared_ptr<Scene> splashScene =  SplashScreenFunc();
	GameManager gm;
	gm.AddScene(splashScene);
	gm.GameLoop();
	return EXIT_SUCCESS;
}

shared_ptr<Scene> SplashScreenFunc()
{
	shared_ptr<Scene> splashScene{new Scene()};
	shared_ptr<GraphicObject> background{new SplashScreen()};
	shared_ptr<SpriteInfo> backgroundInfo =  background->getSpriteInfo();
	backgroundInfo->textureLocation = "resources/MceboDlamini.jpg";
	backgroundInfo->scale = Vector2f(2.5f,2.0f);
	splashScene->Instantiate(background);
	background->setActive(true);
	return splashScene;
}

