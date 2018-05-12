#ifndef KEYBOARDCOMPOSER_H
#define PKEYBOARDCOMPOSER_H
#include "composer.h"
#include <vector>

class keyboardComposer : public composer
{
    public:
        keyboardComposer();
        virtual ~keyboardComposer();

        virtual void update(double t_begin, double t_end);

        sound* generatePianoNote(double f, double l);

    protected:
        struct keyPlayer{
            bool active;
            int keycode;
            double freq;
            double length;
            double vol;
        };
        std::vector<keyPlayer> players;
    private:
};

#endif // KEYBOARDCOMPOSER_H
