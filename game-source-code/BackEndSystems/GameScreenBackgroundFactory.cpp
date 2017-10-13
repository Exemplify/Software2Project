#include "GameScreenBackgroundFactory.h"

GraphicObject GameScreenBackgroundFactory::getGraphicObject()
{
	GraphicObject graphic{"resources/greathall0_hr.png" ,"gameBackground"};
	return graphic;
}
xyVector GameScreenBackgroundFactory::getScale()
{
	xyVector scale{1920.0/914.0,1080.0/569.0};
	return scale;
}