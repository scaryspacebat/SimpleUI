#ifndef GUICHECKBOX_H
#define GUICHECKBOX_H

#include "GuiToggle.h"
#include "GuiHasAdjustablePosXY.h"


class GuiCheckbox : public GuiToggle, public GuiHasAdjustablePosXY {
public:
    GuiCheckbox();
    virtual ~GuiCheckbox();

    virtual void init();

    virtual void render();

protected:

private:
    GLuint cb;
};

#endif // GUICHECKBOX_H
