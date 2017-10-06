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
	shared_ptr<Scene> splashScene = std::make_shared<Scene>();
	shared_ptr<SplashScreen> background = std::make_shared<SplashScreen>("splashScreen");
	shared_ptr<SpriteInfo> backgroundInfo =  background->getSpriteInfo();
	backgroundInfo->textureLocation = "resources/MceboDlamini.png";
	splashScene->Instantiate(background);
	return splashScene;
}

shared_ptr<Scene> GameSceneFunc()
{
	shared_ptr<Scene> gameScene{new Scene()};
	shared_ptr<GraphicObject> background{new SplashScreen("gameBackground")};
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

shared_ptr<Scene> WinScreenFunc()
{
	shared_ptr<Scene> splashScene = std::make_shared<Scene>();
	shared_ptr<SplashScreen> background = std::make_shared<SplashScreen>("WinScreen");
	shared_ptr<SpriteInfo> backgroundInfo =  background->getSpriteInfo();
	backgroundInfo->textureLocation = "resources/WinScreen.png";
	splashScene->Instantiate(background);
	return splashScene;
}

shared_ptr<Scene> LoseScreenFunc()
{
	shared_ptr<Scene> splashScene = std::make_shared<Scene>();
	shared_ptr<SplashScreen> background = std::make_shared<SplashScreen>("LoseScreen");
	shared_ptr<SpriteInfo> backgroundInfo =  background->getSpriteInfo();
	backgroundInfo->textureLocation = "resources/LoseScreen.png";
	splashScene->Instantiate(background);
	return splashScene;
}