#ifndef APPLICATION_H
#define APPLICATION_H

#include "SimpleGui/guiFramework.hpp"
#include "SimpleSound/soundspace.hpp"
#include "SimpleSettings/hasSettings.hpp"
#include "SimpleSettings/SettingBase.hpp"
#include "SimpleSettings/settingInteger.hpp"
#include "SimpleSettings/settingString.hpp"
#include "SimpleSettings/settingBoolean.hpp"
#include "SimpleSettings/settingDouble.hpp"

#include <list>


class ApplicationBase : public hasSettings {
public:
    ApplicationBase();
    virtual ~ApplicationBase();

    void run();

protected:
    virtual void init();

    void initWindow();

    void setSize( unsigned int x, unsigned int y );

    virtual void mainLoop( double dTime )=0;

    int getState();

    void setMode( unsigned int m );

    void setState( unsigned int s );

    void setMeasurementSize( unsigned int ms );

    double getFPS();

    double getMainLoopDuration();
    double getAudioUpdateDuration();

    settingInteger si_size_x;
    settingInteger si_size_y;

    settingString ss_theme;

    GuiFramework gf_gui;
    soundspace ss_audio;

    void setVerticalFOV( double f );

private:
    double d_fovy;
    int i_mode;
    int i_state;

    int i_measurement_size;

    std::list<double> ld_frame_duration;
    std::list<double> ld_main_loop_duration;
    std::list<double> ld_audio_update_duration;

};

#endif // APPLICATION_H
