#include "LoseScreenBackgroundFactory.h"

GraphicObject LoseScreenBackgroundFactory::getGraphicObject()
{
	GraphicObject graphic{"resources/LoseScreen.png" ,"LoseScreen"};
	return graphic;
}
xyVector LoseScreenBackgroundFactory::getScale()
{
	xyVector scale{1,1};
	return scale;
}
