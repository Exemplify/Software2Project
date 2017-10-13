#ifndef LOSE_SCREEN_BACK_FAC
#define LOSE_SCREEN_BACK_FAC
#include "BackgroundObjectFactory.h"

/**
 * @class SplashScreenBackgroundFactory
 * @brief SplashScreenBackgroundFactory is responsible for the construction of any the background object used within the splash screen for the game
 */
class SplashScreenBackgroundFactory: public BackgroundFactory
{
public:
	/**
	 * @brief Function call used to create an PlayerProjectile Object 
	 * @return Returns an GameObject with the specific graphic object for the background of the Splash Screen of the game
	 */
	virtual ~SplashScreenBackgroundFactory() {}
protected:
	/**
	 * @brief Virtual method used to return the specific graphic object for this implementation of the BackgroundFactory type
	 * @return Returns the specific graphic object for the win screens background
	 */
	virtual GraphicObject getGraphicObject() override;
	/**
	 * @brief Virtual method used to return the specific scale for this implementation of the BackgroundFactory type
	 * @return Returns the specific scale object for the win screens background 
	 */
	virtual xyVector getScale() override;
};
#endif