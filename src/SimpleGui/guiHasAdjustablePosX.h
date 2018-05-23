#ifndef GUIHASADJUSTABLEPOSX_H
#define GUIHASADJUSTABLEPOSX_H

#include "guiElement.hpp"


class GuiHasAdjustablePosX : virtual public GuiElement {
    public:
        GuiHasAdjustablePosX();
        virtual ~GuiHasAdjustablePosX();

        void adjustPosX(float x, float rx=0);

    protected:

    private:
};

#endif // GUIHASADJUSTABLEPOSX_H
