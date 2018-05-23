#ifndef GUIISSOLID_H
#define GUIISSOLID_H

#include "guiElement.hpp"


class GuiIsSolid : virtual public GuiElement {
public:
    GuiIsSolid();
    virtual ~GuiIsSolid();

protected:
    virtual bool acceptInput( int mx, int my, int lb, int mb, int rb );

private:
};

#endif // GUIISSOLID_H
