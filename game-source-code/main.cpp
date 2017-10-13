#include "BackEndSystems/GameManager.h"
#include <memory>
#include <iostream>
#include "FrontEndSystems/Scene.h"
#include "BackEndSystems/SplashSceneFactory.h"
#include "BackEndSystems/LoseScreenBackgroundFactory.h"
#include "BackEndSystems/GameScreenBackgroundFactory.h"
#include "BackEndSystems/WinScreenBackgroundFactory.h"
#include "FrontEndSystems/SplashScreen.h"
#include "FrontEndSystems/SpriteInfo.h"
#include "BackEndSystems/Input.h"
#include "BackEndSystems/PlayerFactory.h"
#include "BackEndSystems/EnemyControllerFactory.h"

#include "FrontEndSystems/Player.h"
#include "Vector2D.h"
#include "FrontEndSystems/Character.h"
#include "FrontEndSystems/EnemyController.h"

#include <string>
using std::shared_ptr;

shared_ptr<Scene> GameSceneFunc();
shared_ptr<Scene> WinScreenFunc();
shared_ptr<Scene> LoseScreenFunc();

int main()
{
	SplashSceneFactory splashSceneFactory;
	auto splashScene =  splashSceneFactory.getScene();
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

shared_ptr<Scene> GameSceneFunc()
{
	GameScreenBackgroundFactory gameSceneBackgroundFactory;
	PlayerFactory playerFactory;
	EnemyControllerFactory enemyControllerFactory;
	shared_ptr<Scene> gameScene{new Scene()};

	auto player = playerFactory.getGameObject();
	auto EnemyCon = enemyControllerFactory.getGameObject();
	auto background = gameSceneBackgroundFactory.getGameObject();
	gameScene->Instantiate(background);
	gameScene->Instantiate(player);
	gameScene->Instantiate(EnemyCon);
	return gameScene;
}

shared_ptr<Scene> WinScreenFunc()
{
	shared_ptr<Scene> splashScene = std::make_shared<Scene>();
	WinScreenBackgroundFactory winScreenBackgroundFactory;
	auto background = winScreenBackgroundFactory.getGameObject();
	splashScene->Instantiate(background);
	return splashScene;
}

shared_ptr<Scene> LoseScreenFunc()
{
	shared_ptr<Scene> splashScene = std::make_shared<Scene>();
	LoseScreenBackgroundFactory loseScreenBackgroundFactory;
	auto background = loseScreenBackgroundFactory.getGameObject();
	splashScene->Instantiate(background);
	return splashScene;
}