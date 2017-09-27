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
	shared_ptr<Scene> splashScene = std::make_shared<Scene>();
	shared_ptr<SplashScreen> background = std::make_shared<SplashScreen>();
	shared_ptr<SpriteInfo> backgroundInfo =  background->getSpriteInfo();
	backgroundInfo->textureLocation = "resources/MceboDlamini.png";
	splashScene->Instantiate(background);
	return splashScene;
}

shared_ptr<Scene> GameSceneFunc()
{
	shared_ptr<Scene> gameScene{new Scene()};
	shared_ptr<GraphicObject> background{new SplashScreen()};
	Vector2D<double> playerStart(0,-400,0);
	Character playerStats{3,5};

	shared_ptr<Player> player{new Player(playerStart, playerStats)};
	shared_ptr<SpriteInfo> playerInfo = player->getSpriteInfo();
	playerInfo->textureLocation = "resources/playerSprite.png";
	playerInfo->scale = Vector2f(0.3f,0.3f);
	
	shared_ptr<SpriteInfo> backgroundInfo =  background->getSpriteInfo();
	backgroundInfo->textureLocation = "resources/greathall0_hr.png";
	backgroundInfo->scale = Vector2f(1920.0f/914.0f,1080.0f/569.0f);
	shared_ptr<GameObject> EnemyCon = std::make_shared<EnemyController>();
	
	gameScene->Instantiate(background);
	gameScene->Instantiate(player);
	gameScene->Instantiate(EnemyCon);
	return gameScene;
}