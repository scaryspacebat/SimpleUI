#ifndef GUIHASADJUSTABLEPOSXY_H
#define GUIHASADJUSTABLEPOSXY_H

#include "guiHasAdjustablePosX.h"
#include "guiHasAdjustablePosY.h"


class GuiHasAdjustablePosXY : public GuiHasAdjustablePosX, public GuiHasAdjustablePosY {
    public:
        GuiHasAdjustablePosXY();
        virtual ~GuiHasAdjustablePosXY();

        void adjustPosXY(float x, float y, float rx=0, float ry=0);

    protected:

    private:
};

#endif // GUIHASADJUSTABLEPOSXY_H
