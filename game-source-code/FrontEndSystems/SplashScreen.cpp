#include "SplashScreen.h"
#include "../BackEndSystems/GameManager.h"
#include "../BackEndSystems/Input.h"

const int GameSceneIndex = 1;

void SplashScreen::Update()
{
	QuitGame();
	PlayGame();
}

void SplashScreen::QuitGame()
{
	if(Input::IsButtonPressed(Keys::esc))
		GameManager::Exit();
}
void SplashScreen::PlayGame()
{
	if(Input::IsButtonPressed(Keys::space)&&GameManager::getScene() == 0 )
		GameManager::LoadScene(GameSceneIndex);
}

