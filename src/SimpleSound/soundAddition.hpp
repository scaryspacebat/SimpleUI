#ifndef SOUND_ADD_H
#define SOUND_ADD_H

#include "soundElement.hpp"

#include <vector>


class sound_add : public sound {
public:
    sound_add();
    virtual ~sound_add();

    virtual double get_amplitude( double t, int c );

    virtual double get_duration();

    void add_sound( sound* s );

    void setParent( soundspace* s );

protected:
    std::vector<sound*> sounds;

private:
};

#endif // SOUND_ADD_H
