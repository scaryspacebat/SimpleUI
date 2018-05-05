#ifndef GUI_PROGRESSBAR_H
#define GUI_PROGRESSBAR_H
#include "gui_element.h"

class gui_progressbar : public gui_element
{
    public:
        gui_progressbar();
        virtual ~gui_progressbar();

        virtual void init();

        virtual void draw();

        void set_value(float v);
        float get_value();

    protected:
    private:
        GLuint pb;
        float value;
};

#endif // GUI_PROGRESSBAR_H
