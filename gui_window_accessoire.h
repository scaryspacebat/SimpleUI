#ifndef GUI_WINDOW_ACCESSOIRE_H
#define GUI_WINDOW_ACCESSOIRE_H
#include "gui_element.h"

class gui_window_accessoire : public gui_element
{
    public:
        gui_window_accessoire();
        ~gui_window_accessoire();

        void init();

        void set_type(int t);

        virtual void draw();

        virtual bool take_input();

        virtual int get_state();

    protected:

    private:
        int type;
        GLuint wat;
        int state;
};

#endif // GUI_WINDOW_ACCESSOIRE_H
