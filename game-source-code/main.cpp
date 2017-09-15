#include "BackEndSystems/GameManager.h"
#include <memory>
#include "FrontEndSystems/Scene.h"

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
	
}

