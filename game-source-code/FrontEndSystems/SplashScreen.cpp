#include "SplashScreen.h"
#include "../BackEndSystems/GameManager.h"
#include "../BackEndSystems/Input.h"


void SplashScreen::Update()
{
	QuitGame();
}

void SplashScreen::QuitGame()
{
	if(Input::IsButtonPressed(Keys::esc))
		GameManager::Exit();
}


