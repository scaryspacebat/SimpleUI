#ifndef GUITOGGLE_H
#define GUITOGGLE_H

#include "guiIsClickable.h"

class GuiToggle : public GuiIsClickable {
    public:
        GuiToggle();
        virtual ~GuiToggle();

        virtual bool acceptInput(int mx, int my, int lb, int mb, int rb);

        void setToggleState(bool s);
        bool getToggleState();

    protected:

    private:
        bool b_toggle_state;
};

#endif // GUITOGGLE_H
