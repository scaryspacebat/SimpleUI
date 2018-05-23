#ifndef GUIHASADJUSTABLESIZEX_H
#define GUIHASADJUSTABLESIZEX_H

#include "guiElement.hpp"


class GuiHasAdjustableSizeX : virtual public GuiElement {
public:
    GuiHasAdjustableSizeX();
    virtual ~GuiHasAdjustableSizeX();

    void adjustSizeX( float x, float rx=0 );

protected:

private:
};

#endif // GUIHASADJUSTABLESIZEX_H
