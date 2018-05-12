#include "sound_oscillator.h"

#include "soundspace.h"
#include "log.h"

#include <cmath>

#define M_PI   3.14159265358979323846

sound_oscillator::sound_oscillator()
{
    //ctor
    freq=440;
    offset=0;
}

sound_oscillator::sound_oscillator(double f)
{
    //ctor
    freq=f;
}

sound_oscillator::~sound_oscillator()
{
    //dtor
}

double sound_oscillator::get_amplitude(double t, int c){
    if(parent==nullptr) log::writeToLog("Oscillator can't find soundspace!", -1);
    t=parent->getAbsoluteTime();
    return volume*sin((t+offset/freq)*freq*2.0*M_PI);
}

void sound_oscillator::set_frequency(double f){
    freq=f;
    return;
}

void sound_oscillator::set_type(int t){
    type = t;
    return;
}
