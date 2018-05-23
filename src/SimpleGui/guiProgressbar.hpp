#ifndef GUI_PROGRESSBAR_H
#define GUI_PROGRESSBAR_H

#include "guiIsSolid.h"
#include "GuiHasAdjustableSizeX.h"
#include "guiHasAdjustablePosXY.h"


class GuiProgressbar :  public GuiIsSolid, public GuiHasAdjustableSizeX,
                        public GuiHasAdjustablePosXY {
public:
    GuiProgressbar();
    virtual ~GuiProgressbar();

    virtual void init();

    virtual void render();

    void setValue( float v );
    float getValue();

protected:
private:
    GLuint pb;
    float f_value;
};

#endif // GUI_PROGRESSBAR_H
