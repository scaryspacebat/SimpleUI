#ifndef GUIPOPUPWINDOW_H
#define GUIPOPUPWINDOW_H

#include "guiWindow.hpp"

#include <chrono>


class GuiPopUpWindow : public GuiWindow
{
    public:
        GuiPopUpWindow();
        virtual ~GuiPopUpWindow();

        virtual bool assessInput(int mx, int my, int lb, int mb, int rb);

        virtual void makeVisible();

        void setDelay(double d);

    protected:

    private:
        double delay;
        bool visited;
        std::chrono::steady_clock::time_point lastActivity;
};

#endif // GUIPOPUPWINDOW_H
