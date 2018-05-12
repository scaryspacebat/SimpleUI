#ifndef COMPOSER_H
#define COMPOSER_H

#include "sound.h"

class soundspace;

class composer
{
    public:
        composer();
        virtual ~composer();

        virtual void update(double t_begin, double t_end);

        void set_BPM(double b);

        void setParent(soundspace* p);

        sound* generate_cymbal(double oct, double intv, double ln);
        sound* generate_snare(double oct, double intv, double ln);
        sound* generate_kick(double oct, double intv, double ln);

    protected:
        soundspace* parent;

        double bl;

        double base_freq;

        double octave;

        double intervals;

        int counter;

    private:
};

#endif // COMPOSER_H
