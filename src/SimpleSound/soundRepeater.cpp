#include "soundRepeater.hpp"


sound_repeat::sound_repeat()
{
    //ctor
    interval=5.0;
    csound=nullptr;
}

sound_repeat::~sound_repeat()
{
    //dtor
    delete csound;
}

double sound_repeat::get_amplitude( double t, int c ) {
    return csound->get_amplitude( t-floor( t/interval )*interval, c );
}

void sound_repeat::set_interval_length( double l ) {
    interval=l;
    return;
}

void sound_repeat::set_content( sound* s ) {
    if( csound != nullptr )
        delete csound;
    csound = s;
    return;
}
