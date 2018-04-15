#ifndef GUI_H
#define GUI_H
#include "gui_container.h"

class gui : public gui_container
{
    public:
        gui();
        virtual ~gui();

        virtual void draw();

        virtual float get_abs_pos_x();
        virtual float get_abs_pos_y();

        virtual float get_size_x();
        virtual float get_size_y();

        bool has_recieved_input();

        void set_bg_visibility(bool d);

    protected:
    private:
        GLuint tid;
        bool ui_rec;
        bool bg_visible;
};

#endif // GUI_H
