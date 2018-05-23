#ifndef SOUNDSPACE_H
#define SOUNDSPACE_H

#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <vector>
#include "composerBase.hpp"

class soundspace {
public:
    soundspace();
    virtual ~soundspace();

    void init();

    void update();

    void addComposer( composer* c );

    void addSound( sound* snd );

    double getAbsoluteTime();

protected:
private:
    double getAmplitude( double t, int c );

    int sps;
    int bps;

    double volume;

    int c_block;
    int nr_blocks;
    int nr_channels;
    int p_blocks;
    int blocksize;

    std::vector<composer*> cmpsr;
    std::vector<sound*> sounds;

    double absolute_time;

    WAVEHDR* blocks;
    HWAVEOUT hWaveOut;      /* device handle */
    WAVEFORMATEX wfx;       /* look this up in your documentation */
    MMRESULT result;            /* for waveOut return values */
};

#endif // SOUNDSPACE_H
