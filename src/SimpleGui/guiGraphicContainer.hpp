#ifndef GUI_GRAPHIC_CONTAINER_H
#define GUI_GRAPHIC_CONTAINER_H

#include "GuiContainer.hpp"
#include "guiIsSolid.h"
#include "GuiHasAdjustableSizeXY.h"
#include "guiHasAdjustablePosXY.h"


class GuiGraphicContainer : public GuiContainer, public GuiIsSolid,
                            public GuiHasAdjustableSizeXY, public GuiHasAdjustablePosXY {
public:
    GuiGraphicContainer();
    virtual ~GuiGraphicContainer();

    virtual void init();

    virtual void render();

    void setStyle( int s );

protected:
private:
    GLuint cst1;
    GLuint cst2;
    GLuint cst3;
    int i_style;
};

#endif // GUI_GRAPHIC_CONTAINER_H
