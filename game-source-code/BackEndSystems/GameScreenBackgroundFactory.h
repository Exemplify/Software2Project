#ifndef GAME_SCREEN_BACK_FAC
#define GAME_SCREEN_BACK_FAC
#include "BackgroundObjectFactory.h"
/**
 * @class GameScreenBackgroundFactory
 * @brief GameScreenBackgroundFactory is responsible for the construction of any the background object used within the game scene for the game
 */
class GameScreenBackgroundFactory: public BackgroundFactory
{
public:
	virtual ~GameScreenBackgroundFactory() {}
protected:
	/**
	 * @brief Virtual method used to return the specific graphic object for this implementation of the BackgroundFactory type
	 * @return Returns the specific graphic object for the Game screens background
	 */
	virtual GraphicObject getGraphicObject() override;
	/**
	 * @brief Virtual method used to return the specific scale for this implementation of the BackgroundFactory type
	 * @return Returns the specific scale object for the Game screens background 
	 */
	virtual xyVector getScale() override;
};

#endif