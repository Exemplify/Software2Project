#ifndef WIN_SCREEN_BACK_FAC
#define WIN_SCREEN_BACK_FAC
#include "BackgroundObjectFactory.h"

/**
 * @class WinScreenBackgroundFactory
 * @brief WinScreenBackgroundFactory is responsible for the construction of the background object used within the win screen for the game
 */
class WinScreenBackgroundFactory: public BackgroundFactory
{
public:
	virtual ~WinScreenBackgroundFactory() {}
	
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