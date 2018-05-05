#ifndef GUI_CONTAINER_H
#define GUI_CONTAINER_H
#include "gui_element.h"
#include "chain.h"

class gui_container : public gui_element
{
    public:
        gui_container();
        virtual ~gui_container();

        virtual void init();

        virtual void draw();

        virtual bool take_input();

        void add_element(gui_element* new_el);

        virtual void make_active();
        virtual void make_inactive();
        virtual void make_visible();
        virtual void make_invisible();

    protected:
        chain<gui_element*> content;

    private:
};

#endif // GUI_CONTAINER_H
