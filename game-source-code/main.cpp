#include "BackEndSystems/GameManager.h"
#include <memory>
#include <iostream>
#include "FrontEndSystems/Scene.h"
#include "BackEndSystems/SplashSceneFactory.h"
#include "BackEndSystems/WinSceneFactory.h"
#include "BackEndSystems/LoseSceneFactory.h"
#include "BackEndSystems/GameSceneFactory.h"
#include "BackEndSystems/LoseScreenBackgroundFactory.h"
#include "BackEndSystems/GameScreenBackgroundFactory.h"
#include "BackEndSystems/WinScreenBackgroundFactory.h"
#include "BackEndSystems/SplashScreenBackgroundFactory.h"
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

int main()
{
	SplashSceneFactory splashSceneFactory;
	WinSceneFactory winSceneFactory;
	LoseSceneFactory loseSceneFactory;
	GameSceneFactory gameSceneFactory;
	
	auto splashScene =  splashSceneFactory.getScene();
	auto gameScene = gameSceneFactory.getScene();
	auto winScene = winSceneFactory.getScene();
	auto loseScene = loseSceneFactory.getScene();
	GameManager gm;
	gm.AddScene(splashScene);
	gm.AddScene(gameScene);
	gm.AddScene(winScene);
	gm.AddScene(loseScene);
	gm.GameLoop();
	return EXIT_SUCCESS;
}



