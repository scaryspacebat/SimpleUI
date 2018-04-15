#ifndef GUI_HOR_SLIDER_H
#define GUI_HOR_SLIDER_H
#include "gui_element.h"

class gui_hor_slider : public gui_element
{
    public:
        gui_hor_slider();
        virtual ~gui_hor_slider();

        virtual void draw();

        virtual bool take_input();

        void set_value(float v);
        float get_value();

    protected:
    private:
        static GLuint st;
        float value;
};

#endif // GUI_HOR_SLIDER_H
