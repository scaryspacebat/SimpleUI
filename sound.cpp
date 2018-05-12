#include "sound.h"

#include "soundspace.h"

sound::sound()
{
    //ctor
    volume = 1;
    t_begin=0;
    parent=nullptr;
}

sound::~sound()
{
    //dtor
}

double sound::play(double t, int c){
    double r=0;
    if(t>=t_begin){
        r=get_amplitude(t-t_begin, c);
    }
    return r;
}

double sound::get_duration(){
    return -1;
}

void sound::set_volume(double v){
    volume=v;
    return;
}

void sound::set_beginning(double t){
    t_begin=t;
    return;
}

double sound::get_beginning(){
    return t_begin;
}

void sound::setParent(soundspace* s){
    parent=s;
    return;
}
