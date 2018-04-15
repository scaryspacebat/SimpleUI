#ifndef GUI_GRAPHIC_CONTAINER_H
#define GUI_GRAPHIC_CONTAINER_H
#include "gui_container.h"

class gui_graphic_container : public gui_container
{
    public:
        gui_graphic_container();
        virtual ~gui_graphic_container();

        virtual void draw();

        void set_style(int s);
    protected:
    private:
        static GLuint cst1;
        static GLuint cst2;
        static GLuint cst3;
        int style;
};

#endif // GUI_GRAPHIC_CONTAINER_H
