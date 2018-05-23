#include "guiIsClickable.h"

#include "../log.h"

GuiIsClickable::GuiIsClickable()
{
    //ctor
    i_state=0;
}

GuiIsClickable::~GuiIsClickable()
{
    //dtor
}

int GuiIsClickable::getState() {
    return i_state;
}

bool GuiIsClickable::acceptInput( int mx, int my, int lb, int mb, int rb ) {
    bool r=GuiIsSolid::acceptInput( mx, my, lb, mb, rb );

    if( r==true && isActive() && lb>0) {
        if( i_state==0 || i_state==3 )
            i_state=1;
        else if( i_state==1 )
            i_state=2;
    }
    else {
        if( i_state==1 || i_state==2 )
            i_state=3;
        else if( i_state==3 )
            i_state=0;
    }
    return r;
}
