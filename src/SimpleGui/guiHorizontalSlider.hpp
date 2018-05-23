#ifndef GUI_HOR_SLIDER_H
#define GUI_HOR_SLIDER_H

#include "GuiIsSolid.h"
#include "GuiHasAdjustableSizeX.h"
#include "guiHasAdjustablePosXY.h"


class GuiHorizontalSlider : public GuiIsSolid, public GuiHasAdjustableSizeX,
                            public GuiHasAdjustablePosXY {
public:
    GuiHorizontalSlider();
    virtual ~GuiHorizontalSlider();

    virtual void init();

    virtual void render();

    virtual bool acceptInput( int mx, int my, int lb, int mb, int rb );

    void setValue( float v );
    float getValue();

protected:
private:
    GLuint st;
    float f_value;
};

#endif // GUI_HOR_SLIDER_H
