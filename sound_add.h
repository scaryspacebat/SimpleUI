#ifndef SOUND_ADD_H
#define SOUND_ADD_H

#include "sound.h"
#include <vector>

using namespace std;

class sound_add : public sound
{
    public:
        sound_add();
        virtual ~sound_add();

        virtual double get_amplitude(double t, int c);

        virtual double get_duration();

        void add_sound(sound* s);

        void setParent(soundspace* s);

    protected:
        vector<sound*> sounds;

    private:
};

#endif // SOUND_ADD_H
