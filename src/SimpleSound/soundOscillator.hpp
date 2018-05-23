#ifndef SOUND_OSCILLATOR_H
#define SOUND_OSCILLATOR_H

#include "soundElement.hpp"

class sound_oscillator : public sound {
public:
    sound_oscillator();
    sound_oscillator( double f );
    virtual ~sound_oscillator();

    virtual double get_amplitude( double t, int c=0 );

    void set_frequency( double f );
    void set_type( int t );

protected:
    int type;
    double freq;
    double offset;

private:
};

#endif // SOUND_OSCILLATOR_H
