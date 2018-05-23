#ifndef GUIHASADJUSTABLESIZEXY_H
#define GUIHASADJUSTABLESIZEXY_H

#include "GuiHasAdjustableSizeX.h"
#include "GuiHasAdjustableSizeY.h"


class GuiHasAdjustableSizeXY : public GuiHasAdjustableSizeX, public GuiHasAdjustableSizeY {
    public:
        GuiHasAdjustableSizeXY();
        virtual ~GuiHasAdjustableSizeXY();

        void adjustSizeXY(float x, float y, float rx=0, float ry=0);

    protected:

    private:
};

#endif // GUIHASADJUSTABLESIZEXY_H
