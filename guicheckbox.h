#ifndef GUICHECKBOX_H
#define GUICHECKBOX_H
#include "gui_element.h"

class guiCheckbox : public gui_element
{
    public:
        guiCheckbox();
        virtual ~guiCheckbox();

        virtual void init();

        virtual void draw();

        virtual bool take_input();

        bool get_state();

        void setState(bool s);

    protected:

    private:
        GLuint cb;

        int state;
};

#endif // GUICHECKBOX_H
