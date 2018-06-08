#include "GuiLabeledButton.h"

GuiLabeledButton::GuiLabeledButton()
{
    //ctor
    addElement(&gt_label);
    gt_label.adjustPosY(-6, 0.5);
}

GuiLabeledButton::~GuiLabeledButton()
{
    //dtor
}

void GuiLabeledButton::setLabel(std::string l){
    gt_label.setText(l);
    gt_label.adjustPosX(-gt_label.getSizeX()/2, 0.5);
    return;
}
