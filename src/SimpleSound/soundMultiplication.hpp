#ifndef SOUND_MULTIPLY_H
#define SOUND_MULTIPLY_H
#include "soundAddition.hpp"

class sound_multiply : public sound_add {
public:
    sound_multiply();
    virtual ~sound_multiply();

    virtual double get_amplitude( double t, int c=0 );
    virtual double get_duration();

protected:
private:
};

#endif // SOUND_MULTIPLY_H
