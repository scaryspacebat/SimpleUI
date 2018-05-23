#ifndef GUIHASADJUSTABLEPOSY_H
#define GUIHASADJUSTABLEPOSY_H

#include "guiElement.hpp"


class GuiHasAdjustablePosY : virtual public GuiElement {
    public:
        GuiHasAdjustablePosY();
        virtual ~GuiHasAdjustablePosY();

        void adjustPosY(float y, float ry=0);

    protected:

    private:
};

#endif // GUIHASADJUSTABLEPOSY_H
