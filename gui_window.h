#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H
#include "gui_container.h"

class gui_window : public gui_container
{
    public:
        gui_window();
        virtual ~gui_window();

        virtual void draw();

        virtual bool take_input();

        void autohide(bool v);

        bool has_hidden();

    protected:
    private:
        static GLuint wbg;
        bool vanish;
        bool has_vanished;
};

#endif // GUI_WINDOW_H
