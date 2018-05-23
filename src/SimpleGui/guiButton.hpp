#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H

#include "guiContainer.hpp"
#include "guiIsClickable.h"
#include "GuiHasAdjustableSizeXY.h"
#include "guiHasAdjustablePosXY.h"


class GuiButton :   public GuiIsClickable, public GuiHasAdjustableSizeXY,
                    public GuiContainer, public GuiHasAdjustablePosXY {
public:
    GuiButton();
    virtual ~GuiButton();

    virtual void init();

    virtual void render();

    /*virtual float get_abs_pos_x();
    virtual float get_abs_pos_y();

    virtual float get_pos_x();
    virtual float get_pos_y();*/

protected:
private:
    GLuint bt;
    GLuint bpt;

    float off_x;
    float off_y;

};

#endif // GUI_BUTTON_H
