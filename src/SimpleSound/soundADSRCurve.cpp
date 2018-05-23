#include "soundADSRCurve.hpp"


adsr::adsr()
{
    //ctor
    /*
    a_dur=0.1;
    d_dur=0.2;
    s_dur=0.5;
    s_lev=0.3;
    r_dur=0.2;//*/
    //*
    a_dur=0.2;
    d_dur=0.3;
    s_dur=1.0;
    s_lev=0.3;
    r_dur=1.5;//*/
}

adsr::~adsr()
{
    //dtor
}

double adsr::get_amplitude( double t, int c ) {
    double r=0;
    if( t>0                  && t<=a_dur )
        r=t/a_dur;
    if( t>a_dur              && t<=a_dur+d_dur )
        r=s_lev+( 1-s_lev )*( 1-( t-a_dur )/d_dur );
    if( t>a_dur+d_dur        && t<=a_dur+d_dur+s_dur )
        r=s_lev;
    if( t>a_dur+d_dur+s_dur  && t<=a_dur+d_dur+s_dur+r_dur )
        r=s_lev*( 1-( t-( a_dur+d_dur+s_dur ) )/r_dur );
    return r*volume;
}

double adsr::get_duration() {
    return a_dur+d_dur+s_dur+r_dur;
}

void adsr::set_shape( double ad, double dd, double sl, double sd, double rd ) {
    a_dur=ad;
    d_dur=dd;
    s_lev=sl;
    s_dur=sd;
    r_dur=rd;
    return;
}
