#include "SplashScreenBackgroundFactory.h"

GraphicObject SplashScreenBackgroundFactory::getGraphicObject()
{
	GraphicObject graphic{"resources/MceboDlamini.png" ,"splashScreen"};
	return graphic;
}
xyVector SplashScreenBackgroundFactory::getScale()
{
	xyVector scale{1,1};
	return scale;
}
