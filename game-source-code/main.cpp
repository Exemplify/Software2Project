#include "BackEndSystems/GameManager.h"
#include <memory>
#include <iostream>
#include "FrontEndSystems/Scene.h"
#include "FrontEndSystems/SplashScreen.h"
#include "FrontEndSystems/SpriteInfo.h"
#include "BackEndSystems/Input.h"
#include "FrontEndSystems/Player.h"
#include "Vector2D.hpp"
#include "FrontEndSystems/Character.h"
#include "FrontEndSystems/EnemyController.h"
#include <string>
using std::shared_ptr;

shared_ptr<Scene> SplashScreenFunc();
shared_ptr<Scene> GameSceneFunc();
shared_ptr<Scene> WinScreenFunc();
shared_ptr<Scene> LoseScreenFunc();

int main()
{
	auto splashScene =  SplashScreenFunc();
	auto gameScene = GameSceneFunc();
	auto winScene = WinScreenFunc();
	auto loseScene = LoseScreenFunc();
	GameManager gm;
	gm.AddScene(splashScene);
	gm.AddScene(gameScene);
	gm.AddScene(winScene);
	gm.AddScene(loseScene);
	gm.GameLoop();
	return EXIT_SUCCESS;
}

shared_ptr<Scene> SplashScreenFunc()
{
	
	auto splashScene = std::make_shared<Scene>();
	auto splashScreenGraphic = GraphicObject("resources/MceboDlamini.png" ,"splashScreen");
	shared_ptr<SplashScreen> background = std::make_shared<SplashScreen>(splashScreenGraphic, xyVector(1,1));
	splashScene->Instantiate(background);
	return splashScene;
}

shared_ptr<Scene> GameSceneFunc()
{

	shared_ptr<Scene> gameScene{new Scene()};
	auto gameSceneGraphic = GraphicObject("resources/greathall0_hr.png" ,"gameBackground");
	auto background = std::make_shared<SplashScreen>(gameSceneGraphic, xyVector(1920.0/914.0,1080.0/569.0));
	Vector2D<double> playerStart(0,-400,0);
	Character playerStats{3,5};

	shared_ptr<GameObject> player = std::make_shared<Player>(playerStart, playerStats);
	shared_ptr<GameObject> EnemyCon = std::make_shared<EnemyController>();
	
	gameScene->Instantiate(background);
	gameScene->Instantiate(player);
	gameScene->Instantiate(EnemyCon);
	return gameScene;
}

shared_ptr<Scene> WinScreenFunc()
{
	shared_ptr<Scene> splashScene = std::make_shared<Scene>();
	auto winSceneGraphic = GraphicObject("resources/WinScreen.png" ,"WinScreen");
	shared_ptr<SplashScreen> background = std::make_shared<SplashScreen>(winSceneGraphic, xyVector(1,1));
	splashScene->Instantiate(background);
	return splashScene;
}

shared_ptr<Scene> LoseScreenFunc()
{
	shared_ptr<Scene> splashScene = std::make_shared<Scene>();
	auto loseSceneGraphic = GraphicObject("resources/LoseScreen.png" ,"LoseScreen");
	shared_ptr<SplashScreen> background = std::make_shared<SplashScreen>(loseSceneGraphic, xyVector(1,1));
	splashScene->Instantiate(background);
	return splashScene;
}