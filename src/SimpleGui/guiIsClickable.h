#ifndef GUIISCLICKABLE_H
#define GUIISCLICKABLE_H

#include "guiIsSolid.h"


class GuiIsClickable : virtual public GuiIsSolid {
public:
    GuiIsClickable();
    virtual ~GuiIsClickable();

    int getState();

    virtual bool acceptInput( int mx, int my, int lb, int mb, int rb );

protected:
    int i_state;

private:
};

#endif // GUIISCLICKABLE_H
