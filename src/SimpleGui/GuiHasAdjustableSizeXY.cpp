#include "GuiHasAdjustableSizeXY.h"


GuiHasAdjustableSizeXY::GuiHasAdjustableSizeXY()
{
    //ctor
}

GuiHasAdjustableSizeXY::~GuiHasAdjustableSizeXY()
{
    //dtor
}

void GuiHasAdjustableSizeXY::adjustSizeXY(float x, float y, float rx, float ry){
    adjustSizeX(x, rx);
    adjustSizeY(y, ry);
    return;
}
