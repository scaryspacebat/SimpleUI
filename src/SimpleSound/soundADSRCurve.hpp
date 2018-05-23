#ifndef ADSR_H
#define ADSR_H

#include "soundElement.hpp"


class adsr : public sound {
public:
    adsr();
    virtual ~adsr();

    virtual double get_amplitude( double t, int c=0 );

    virtual double get_duration();

    void set_shape( double ad, double dd, double sl, double sd, double rd );

protected:
private:
    double a_dur;
    double d_dur;
    double s_lev;
    double s_dur;
    double r_dur;
};

#endif // ADSR_H
