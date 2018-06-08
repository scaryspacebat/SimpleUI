#ifndef GUILABELEDBUTTON_H
#define GUILABELEDBUTTON_H

#include "guiButton.hpp"
#include "guiTextLine.hpp"

#include <string>


class GuiLabeledButton : public GuiButton {
    public:
        GuiLabeledButton();
        virtual ~GuiLabeledButton();

        void setLabel(std::string l);

    protected:
        GuiTextLine gt_label;

    private:
};

#endif // GUILABELEDBUTTON_H
