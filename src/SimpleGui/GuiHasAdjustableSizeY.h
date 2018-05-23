#ifndef GUIHASADJUSTABLESIZEY_H
#define GUIHASADJUSTABLESIZEY_H

#include "guiElement.hpp"


class GuiHasAdjustableSizeY : virtual public GuiElement {
public:
    GuiHasAdjustableSizeY();
    virtual ~GuiHasAdjustableSizeY();

    void adjustSizeY( float y, float ry=0 );

protected:

private:
};

#endif // GUIHASADJUSTABLESIZEY_H
