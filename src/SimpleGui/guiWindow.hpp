#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H

#include "guiContainer.hpp"
#include "guiIsSolid.h"
#include "GuiHasAdjustableSizeXY.h"
#include "guiHasAdjustablePosXY.h"


class GuiWindow :   public GuiContainer, public GuiIsSolid,
                    public GuiHasAdjustableSizeXY, public GuiHasAdjustablePosXY {
public:
    GuiWindow();
    virtual ~GuiWindow();

    virtual void init();

    virtual void render();

    //virtual bool take_input();

    //void autohide( bool v );

    //bool has_hidden();

protected:
private:
    GLuint wbg;
    //bool vanish;
    //bool has_vanished;
};

#endif // GUI_WINDOW_H
