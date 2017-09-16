#include "BackEndSystems/GameManager.h"
#include <memory>
#include "FrontEndSystems/Scene.h"
#include "FrontEndSystems/GraphicObject.h"
#include "FrontEndSystems/SpriteInfo.h"

using std::shared_ptr;

shared_ptr<Scene> SplashScreen();

int main()
{
	shared_ptr<Scene> ss =  SplashScreen();
	GameManager gm;
	gm.AddScene(ss);
	gm.GameLoop();
	
	return EXIT_SUCCESS;
}

shared_ptr<Scene> SplashScreen()
{
	shared_ptr<Scene> splashScene{new Scene()};
	shared_ptr<GraphicObject> background{new GraphicObject()};
	shared_ptr<SpriteInfo> backgroundInfo =  background->getSpriteInfo();
	backgroundInfo->textureLocation = "resources/MceboDlamini.jpg";
	backgroundInfo->scale = Vector2f(2.5f,2.0f);
	splashScene->Instantiate(background);
	background->setActive(true);
	return splashScene;
}

