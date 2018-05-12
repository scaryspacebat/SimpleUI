#include <cmath>
#include <iostream>

#include "composer.h"
#include "soundspace.h"
#include "simpleui.h"

#include "sound_multiply.h"
#include "sound_add.h"
#include "sound_repeat.h"
#include "sound_oscillator.h"
#include "adsr.h"

using namespace std;

composer::composer()
{
    //ctor
    set_BPM(120);
    base_freq = 440*4;
    octave = 2;
    intervals = 12;
    counter = 0;
    parent = nullptr;
}

composer::~composer()
{
    //dtor
}

void composer::update(double t_begin, double t_end){
    //*
    while(t_end>=counter*bl){
        if(parent==nullptr) log::writeToLog("Composer can't find soundspace!", -1);
        if(counter%2==0 || counter%16==15){
            sound* d = generate_cymbal(-2, 0, 1);
            d->set_beginning(counter*bl);
            d->set_volume(0.3);

            parent->addSound(d);
        }

        if(counter%16<8){
            sound* d = generate_cymbal(-3,  0, 0.3);
            d->set_beginning(counter*bl);
            d->set_volume(0.3);
            parent->addSound(d);

            d = generate_cymbal(-3, 3, 0.3);
            d->set_beginning((static_cast<double>(counter)+0.5)*bl);
            d->set_volume(0.3);
            parent->addSound(d);
        }


        if(counter%16==4 || counter%16==12){
            sound* d = generate_snare(-2, 8, 1);
            d->set_beginning(counter*bl);
            d->set_volume(0.3);

            parent->addSound(d);
        }

        if(counter%16==0 || counter%16==10){
            sound* d = generate_kick(-3, -5, 1);
            d->set_beginning(counter*bl);
            d->set_volume(0.3);

            parent->addSound(d);
        }
        counter++;
    }
    //*/
    return;
}

void composer::set_BPM(double b){
    bl = 60.0/b;
    return;
}

void composer::setParent(soundspace* p){
    parent = p;
    return;
}

sound* composer::generate_cymbal(double oct, double intvl, double ln){
    sound_multiply* r = new sound_multiply;
    r->add_sound(new sound_oscillator(base_freq*pow(octave, oct)*pow(pow(octave, 1/intervals), intvl)));
    adsr* hull = new adsr;
    hull->set_shape(0.1*ln, 0.3*ln, 0.3, 0.3*ln, 0.3*ln);
    r->add_sound(hull);
    return r;
}

sound* composer::generate_snare(double oct, double intvl, double ln){
    sound_multiply* r = new sound_multiply;
    r->add_sound(new sound_oscillator(base_freq*pow(octave, oct)*pow(pow(octave, 1/intervals), intvl)));
    adsr* hull = new adsr;
    hull->set_shape(0.1*ln, 0.3*ln, 0.3, 0.3*ln, 0.3*ln);
    r->add_sound(hull);
    return r;
}

sound* composer::generate_kick(double oct, double intvl, double ln){
    sound_multiply* r = new sound_multiply;
    r->add_sound(new sound_oscillator(base_freq*pow(octave, oct)*pow(pow(octave, 1/intervals), intvl)));
    adsr* hull = new adsr;
    hull->set_shape(0.1*ln, 0.3*ln, 0.3, 0.3*ln, 0.3*ln);
    r->add_sound(hull);
    return r;
}
