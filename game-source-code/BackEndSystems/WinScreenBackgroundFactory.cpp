#include "WinScreenBackgroundFactory.h"

GraphicObject WinScreenBackgroundFactory::getGraphicObject()
{
	GraphicObject graphic{"resources/WinScreen.png" ,"WinScreen"};
	return graphic;
}

xyVector WinScreenBackgroundFactory::getScale()
{
	xyVector scale{1,1};
	return scale;
}
