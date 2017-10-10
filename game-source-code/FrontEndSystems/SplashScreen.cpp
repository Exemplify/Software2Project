#include "SplashScreen.h"
#include "../BackEndSystems/GameManager.h"
#include "../BackEndSystems/Input.h"

/// This needs to be rethought for the use of playing game based on the current Scene
/// Cound rather be a composition or seperate the control of loading a new scene into a new object
const int GameSceneIndex = 1;
SplashScreen::SplashScreen(GraphicObject graphicObject, xyVector scale)
{
	_scale = scale;
	_graphicObject = graphicObject;
}
void SplashScreen::Update()
{
	QuitGame();
	PlayGame();
}
// Quits the game when the escape button is pressed 
void SplashScreen::QuitGame()
{
	if(Input::IsButtonPressed(Keys::esc))
		GameManager::Exit();
}
// loads the game scene when the current scene is the splashScreen
void SplashScreen::PlayGame()
{
	if(Input::IsButtonPressed(Keys::space)&&GameManager::getScene() == 0 )
		GameManager::LoadScene(GameSceneIndex);
}

