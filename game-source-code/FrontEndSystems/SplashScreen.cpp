#include "SplashScreen.h"
#include "../BackEndSystems/Application.h"
#include "../BackEndSystems/Input.h"


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
	if(Input::IsButtonPressed(Keys::enter))
		Application::LoadScene(GameSceneIndex);
}

