#include "GuiPopUpWindow.h"

GuiPopUpWindow::GuiPopUpWindow()
{
    //ctor
    setDelay(0.5);
    visited=false;
    makeInvisible();
}

GuiPopUpWindow::~GuiPopUpWindow()
{
    //dtor
}


bool GuiPopUpWindow::assessInput(int mx, int my, int lb, int mb, int rb){
    bool r = GuiContainer::assessInput(mx, my, lb, mb, rb);

    if(r==true){
        lastActivity=std::chrono::steady_clock::now();
        visited=true;
    }

    if(std::chrono::duration_cast<std::chrono::duration<double>>( std::chrono::steady_clock::now() - lastActivity).count()>delay && visited==true){
        makeInvisible();
    }

    return r;
}

void GuiPopUpWindow::makeVisible(){
    lastActivity=std::chrono::steady_clock::now();
    visited=false;
    GuiElement::makeVisible();
    return;
}

void GuiPopUpWindow::setDelay(double d){
    delay=d;
    return;
}
