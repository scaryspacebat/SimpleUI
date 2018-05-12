#ifndef APPLICATION_H
#define APPLICATION_H

#include "gui.h"
#include "soundspace.h"

class application
{
    public:
        application();
        virtual ~application();

        virtual void init();

        void init_window();

        void set_size(int x, int y);

        void run();

        virtual void main_loop();

        int get_state();

        void setMode(int m);

        void setState(int s);

    protected:
        int size_x;
        int size_y;

        gui Gui;
        soundspace audio;

        void setVerticalFOV(double f);

    private:
        double fovy;
        int mode;
        int state;
};

#endif // APPLICATION_H
