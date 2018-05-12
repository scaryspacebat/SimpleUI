#ifndef SOUND_H
#define SOUND_H

class soundspace;

class sound
{
    public:
        sound();
        virtual ~sound();

        virtual double get_amplitude(double t, int c=0) = 0;
        double play(double t, int c=0);

        virtual double get_duration();

        void set_volume(double v);

        void set_beginning(double t);
        double get_beginning();

        virtual void setParent(soundspace* s);

    protected:
        double volume;
        double t_begin;

        soundspace* parent;

    private:
};

#endif // SOUND_H
