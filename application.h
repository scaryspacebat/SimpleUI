#ifndef APPLICATION_H
#define APPLICATION_H
#include <string>

#include "gui.h"
#include "gui_window.h"
#include "gui_text.h"
#include "gui_button.h"
#include "gui_graphic_container.h"
#include "gui_graphic.h"
#include "gui_progressbar.h"
#include "guicheckbox.h"

using namespace std;

class application
{
    public:
        application();
        virtual ~application();

        virtual void init();

        void init_window();

        void set_size(int x, int y);

        void loop();

        virtual void main_loop();

        int get_state();

    protected:
        int size_x;
        int size_y;

        int state;

        gui Gui;

        void setVerticalFOV(double f);

    private:
        double fovy;
};

#endif // APPLICATION_H
