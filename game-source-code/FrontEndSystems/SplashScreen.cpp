#include "SplashScreen.h"
#include "../BackEndSystems/Application.h"
#include "../BackEndSystems/Input.h"

/// This needs to be rethought for the use of playing game based on the current Scene
/// Cound rather be a composition or seperate the control of loading a new scene into a new object
const int GameSceneIndex = 1;
SplashScreen::SplashScreen(const GameObject& gameObject):
GameObject(gameObject)
{}
void SplashScreen::Update()
{
	PlayGame();
	QuitGame();
}
// Quits the game when the escape button is pressed 
void SplashScreen::QuitGame()
{
	if(Input::IsButtonPressed(Keys::esc))
		Application::CloseApplication();
}
// loads the game scene when the current scene is the splashScreen
void SplashScreen::PlayGame()
{
	if(Input::IsButtonPressed(Keys::space)&& Application::currentSceneIndex() != GameSceneIndex)
		Application::LoadScene(1);
}

