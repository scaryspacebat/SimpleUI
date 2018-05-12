#include "sound_multiply.h"

sound_multiply::sound_multiply()
{
    //ctor
}

sound_multiply::~sound_multiply()
{
    //dtor
}

double sound_multiply::get_amplitude(double t, int c){
    double r=1;
    for(int i=0; i<sounds.size(); i++){
        r*=sounds[i]->get_amplitude(t, c);
    }
    return r*volume;
}

double sound_multiply::get_duration(){
    double r=-1;
    for(int i=0; i<sounds.size(); i++){
        double d = sounds[i]->get_duration();
        if(r==-1){
            r=d;
        }
        else{
            if(d!=-1 && d<r){
                r=d;
            }
        }
    }
    return r;
}
