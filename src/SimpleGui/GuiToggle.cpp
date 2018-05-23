#include "guiToggle.h"

#include "../log.h"


GuiToggle::GuiToggle()
{
    //ctor
    b_toggle_state=false;
}

GuiToggle::~GuiToggle()
{
    //dtor
}

bool GuiToggle::acceptInput(int mx, int my, int lb, int mb, int rb){
    bool r=GuiIsClickable::acceptInput(mx, my, lb, mb, rb);
    if(getState()==3){
        b_toggle_state=!b_toggle_state;
    }
    return r;
}

void GuiToggle::setToggleState(bool s){
    b_toggle_state=s;
    return;
}

bool GuiToggle::getToggleState(){
    return b_toggle_state;
}
