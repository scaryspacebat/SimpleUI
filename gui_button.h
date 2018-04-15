#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H
#include "gui_container.h"

class gui_button : public gui_container
{
    public:
        gui_button();
        virtual ~gui_button();

        virtual void draw();

        virtual bool take_input();

        int get_state();

        /*virtual float get_abs_pos_x();
        virtual float get_abs_pos_y();

        virtual float get_pos_x();
        virtual float get_pos_y();*/

    protected:
    private:
        static GLuint bt;
        static GLuint bpt;

        int state;

        float off_x;
        float off_y;
};

#endif // GUI_BUTTON_H
