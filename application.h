#ifndef APPLICATION_H
#define APPLICATION_H

#include "gui.h"
#include "soundspace.h"
#include "hasSettings.h"
#include "setting.h"
#include "settingInteger.h"
#include "settingString.h"
#include "settingBoolean.h"
#include "settingDouble.h"

#include <list>

class application : public hasSettings
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

        void setMeasurementSize(int m);

        double getFPS();

        double getMainLoopDuration();
        double getAudioUpdateDuration();

    protected:
        settingInteger sizeX;
        settingInteger sizeY;
        int size_x;
        int size_y;

        settingString theme;

        gui Gui;
        soundspace audio;

        void setVerticalFOV(double f);

    private:
        double fovy;
        int mode;
        int state;

        int measurement_size;

        std::list<double> frameDur;
        std::list<double> mlDur;
        std::list<double> aDur;


};

#endif // APPLICATION_H
