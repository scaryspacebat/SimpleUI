#include "guiHasAdjustablePosY.h"

GuiHasAdjustablePosY::GuiHasAdjustablePosY()
{
    //ctor
}

GuiHasAdjustablePosY::~GuiHasAdjustablePosY()
{
    //dtor
}

void GuiHasAdjustablePosY::adjustPosY(float y, float ry){
    setPosY(y, ry);
    return;
}
