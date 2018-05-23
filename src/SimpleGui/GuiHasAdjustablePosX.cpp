#include "guiHasAdjustablePosX.h"

GuiHasAdjustablePosX::GuiHasAdjustablePosX()
{
    //ctor
}

GuiHasAdjustablePosX::~GuiHasAdjustablePosX()
{
    //dtor
}

void GuiHasAdjustablePosX::adjustPosX(float x, float rx){
    setPosX(x, rx);
    return;
}
