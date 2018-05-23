#include "GuiHasAdjustablePosXY.h"

GuiHasAdjustablePosXY::GuiHasAdjustablePosXY()
{
    //ctor
}

GuiHasAdjustablePosXY::~GuiHasAdjustablePosXY()
{
    //dtor
}

void GuiHasAdjustablePosXY::adjustPosXY(float x, float y, float rx, float ry){
    adjustPosX(x, rx);
    adjustPosY(y, ry);
    return;
}
