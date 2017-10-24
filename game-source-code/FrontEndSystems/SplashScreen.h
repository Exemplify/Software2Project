#ifndef SPLASH_H
#define SPLASH_H

#include "GameObject.h"

/**
 * @class SplashScreen
 * @brief SplashScreen is used to represent a background image within the game and has the 
 * responsibility of loading the game scene and exiting the game
 * @details The class responsibilities of this class are should rather be seperated into a BackgroundObject and a 
 * MenuController object it is currently designed incorrectly
 */
class SplashScreen: public GameObject
{
public:
	/**
	 * @brief The constructor for a splashscreen takes in a gameobject 
	 * which is copied into the base gameobject of class to define the base parameters
	 * @param gameObject GameObject that contains the base parameters for the current instance of the SplashScreen
	 */
	SplashScreen(const GameObject& gameObject);
	/**
	 * @brief Checks for user input to identify if the Game Scene should be loaded/Restarted or if the game should exit
	 */
	void Update() override;
private:
	/**
	 * @brief Quits the game when escape is pressed 
	 */
	void QuitGame();
	/**
	 * @brief Loads the game Scene when Enter is pressed
	 */
	void PlayGame();
};

#endif 