#ifndef SOUND_REPEAT_H
#define SOUND_REPEAT_H

#include "soundElement.hpp"

#include <cmath>


class sound_repeat : public sound {
public:
    sound_repeat();
    virtual ~sound_repeat();

    virtual double get_amplitude( double t, int c=0 );

    void set_interval_length( double l );

    void set_content( sound* s );

protected:
    double interval;
    sound* csound;

private:
};

#endif // SOUND_REPEAT_H
