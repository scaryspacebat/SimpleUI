#include "guiIsSolid.h"

GuiIsSolid::GuiIsSolid()
{
    //ctor
}

GuiIsSolid::~GuiIsSolid()
{
    //dtor
}


bool GuiIsSolid::acceptInput( int mx, int my, int lb, int mb, int rb ) {
    if( getSizeX()!=0 && getSizeY()!=0 ) {
        if( mx>=getAbsPosX() && mx<=getAbsPosX()+getSizeX() &&
            my>=getAbsPosY() && my<=getAbsPosY()+getSizeY() )
        return true;
    }
    return false;
}
