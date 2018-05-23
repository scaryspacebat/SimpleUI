#include "soundAddition.hpp"

#include <algorithm>


sound_add::sound_add()
{
    //ctor
}

sound_add::~sound_add()
{
    //dtor
    for( int i=0; i<sounds.size(); i++ )
        delete sounds[i];
    sounds.clear();
}

double sound_add::get_amplitude( double t, int c ) {
    double r=0;
    for( int i=0; i<sounds.size(); i++ )
        r+=sounds[i]->get_amplitude( t, c );
    return r*volume;
}

double sound_add::get_duration() {
    double r=0;
    for( int i=0; i<sounds.size(); i++ )
        r=std::max( r, sounds[i]->get_duration() );
    return r;
}

void sound_add::add_sound( sound* s ) {
    s->setParent( parent );
    sounds.push_back( s );
    return;
}

void sound_add::setParent( soundspace* s ) {
    parent=s;
    for( int i=0; i<sounds.size(); i++ )
        sounds[i]->setParent( parent );
    return;
}
