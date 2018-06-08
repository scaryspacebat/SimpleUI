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

    void setType(int t);

protected:

private:
    GLuint cb;
    int type;
};

#endif // GUICHECKBOX_H
