#ifndef GUI_GRAPHIC_CONTAINER_H
#define GUI_GRAPHIC_CONTAINER_H
#include "gui_container.h"

class gui_graphic_container : public gui_container
{
    public:
        gui_graphic_container();
        virtual ~gui_graphic_container();

        virtual void init();

        virtual void draw();

        void set_style(int s);
    protected:
    private:
        GLuint cst1;
        GLuint cst2;
        GLuint cst3;
        int style;
};

#endif // GUI_GRAPHIC_CONTAINER_H
