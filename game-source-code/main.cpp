#include "BackEndSystems/GameManager.h"
#include <memory>
#include "FrontEndSystems/Scene.h"
#include "FrontEndSystems/GraphicObject.h"
#include "FrontEndSystems/SpriteInfo.h"

using std::shared_ptr;

shared_ptr<Scene> SplashScreen();

int main()
{
	
	GameManager gm;
	gm.GameLoop();
	
	return EXIT_SUCCESS;
}

shared_ptr<Scene> SplashScreen()
{
	shared_ptr<Scene> splashScene{new Scene()};
	GraphicObject* background = new GraphicObject();
	shared_ptr<SpriteInfo> backgroundInfo =  background->getSpriteInfo();
	backgroundInfo->textureLocation = "resources/PlayerShield.png";
	splashScene->Instantiate(background);
	return splashScene;
	
}

