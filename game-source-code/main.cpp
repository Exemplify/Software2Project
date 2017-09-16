#include "BackEndSystems/GameManager.h"
#include <memory>
#include <iostream>
#include "FrontEndSystems/Scene.h"
#include "FrontEndSystems/SplashScreen.h"
#include "FrontEndSystems/SpriteInfo.h"
#include "BackEndSystems/Input.h"

using std::shared_ptr;
shared_ptr<Scene> SplashScreenFunc();
shared_ptr<Scene> GameSceneFunc();

int main()
{
	shared_ptr<Scene> splashScene =  SplashScreenFunc();
	shared_ptr<Scene> gameScene = GameSceneFunc();
	GameManager gm;
	gm.AddScene(splashScene);
	gm.AddScene(gameScene);
	gm.GameLoop();
	return EXIT_SUCCESS;
}

shared_ptr<Scene> SplashScreenFunc()
{
	shared_ptr<Scene> splashScene{new Scene()};
	shared_ptr<SplashScreen> background{new SplashScreen()};
	shared_ptr<SpriteInfo> backgroundInfo =  background->getSpriteInfo();
	backgroundInfo->textureLocation = "resources/MceboDlamini.jpg";
	backgroundInfo->scale = Vector2f(2.5f,2.0f);
	splashScene->Instantiate(background);
	background->setActive(true);
	return splashScene;
}

shared_ptr<Scene> GameSceneFunc()
{
	shared_ptr<Scene> gameScene{new Scene()};
	shared_ptr<GraphicObject> background{new GraphicObject()};
	shared_ptr<SpriteInfo> backgroundInfo =  background->getSpriteInfo();
	backgroundInfo->textureLocation = "resources/greathall0_hr.jpg";
	backgroundInfo->scale = Vector2f(2.0f,2.0f);
	gameScene->Instantiate(background);
	background->setActive(true);
	return gameScene;
}