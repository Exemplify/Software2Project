#ifndef WIN_SCREEN_BACK_FAC
#define WIN_SCREEN_BACK_FAC
#include "BackgroundFactory.h"

/**
 * @class WinScreenBackgroundFactory
 * @brief WinScreenBackgroundFactory is responsible for the construction of the background object used within the win screen for the game
 */
class WinScreenBackgroundFactory: public BackgroundFactory
{
public:
	virtual ~WinScreenBackgroundFactory() {}
};
#endif