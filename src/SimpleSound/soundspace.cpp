#include "soundspace.hpp"

#include "../log.h"

#define MAX_V 32767

soundspace::soundspace()
{
    log::writeToLog( "Creating soundspace" );
    log::addTab();
    sps=44100; // samples per second
    bps=16; // bits per sample

    volume=1.0;

    nr_blocks=3;
    nr_channels=1;
    c_block=0;
    p_blocks=0;

    blocks = new WAVEHDR[nr_blocks];

    blocksize=sps*0.1;

    absolute_time=0;

    for( int i=0; i<nr_blocks; i++ )
    {
        ZeroMemory( &blocks[i], sizeof( WAVEHDR ) );
        blocks[i].dwBufferLength = blocksize*nr_channels;
        blocks[i].lpData = ( LPSTR )( new short[blocksize*nr_channels] );
    }

    log::removeTab();
    log::writeToLog( "Finished creating soundspace" );
}

soundspace::~soundspace()
{
    //dtor

    waveOutClose( hWaveOut );
}

void soundspace::init()
{
    log::writeToLog( "Initiating soundspace" );
    log::addTab();
    //ctor
    wfx.nSamplesPerSec = sps; /* sample rate */
    wfx.wBitsPerSample = bps; /* sample size */
    wfx.nChannels = nr_channels; /* channels*/
    /*
     * WAVEFORMATEX also has other fields which need filling.
     * as long as the three fields above are filled this should
     * work for any PCM (pulse code modulation) format.
     */
    wfx.cbSize = 0; /* size of _extra_ info */
    wfx.wFormatTag = WAVE_FORMAT_PCM;
    wfx.nBlockAlign = ( wfx.wBitsPerSample >> 3 ) * wfx.nChannels;
    wfx.nAvgBytesPerSec = wfx.nBlockAlign * wfx.nSamplesPerSec;
    /*
     * try to open the default wave device. WAVE_MAPPER is
     * a constant defined in mmsystem.h, it always points to the
     * default wave device on the system (some people have 2 or
     * more sound cards).
     */
    if( waveOutOpen(
                &hWaveOut,
                WAVE_MAPPER,
                &wfx,
                0,
                0,
                CALLBACK_NULL
            ) != MMSYSERR_NOERROR )
    {
        log::writeToLog( "Unable to open WAVE_MAPPER device", -1 );
        //ExitProcess(1);
    }

    log::removeTab();
    log::writeToLog( "Finished initiating soundspace" );
    log::nextLine();
    return;
}

void soundspace::update()
{
    int dummy = 0;
    while( ( ( blocks[c_block].dwFlags & WHDR_INQUEUE )==0 || ( blocks[c_block].dwFlags & WHDR_DONE )!=0 ) && sounds.size()>0 && cmpsr.size()>0 )
    {
        dummy++;
        waveOutUnprepareHeader( hWaveOut, &blocks[c_block], sizeof( WAVEHDR ) );

        double t_begin = static_cast<double>( p_blocks )*( static_cast<double>( blocksize )/static_cast<double>( sps ) );
        double t_end = static_cast<double>( p_blocks+1 )*( static_cast<double>( blocksize )/static_cast<double>( sps ) );

        // remove all expired sounds
        int c=0;
        while( c < sounds.size() )
        {
            if( sounds[c]->get_duration()!=-1 && sounds[c]->get_beginning()+sounds[c]->get_duration() < t_end )
            {
                delete sounds[c];
                sounds.erase( sounds.begin()+c );
            }
            else
                c++;
        }

        // add new sounds
        for( int i=0; i<cmpsr.size(); i++ )
            cmpsr[i]->update( t_begin, t_end );

        // fill the current block
        for( int i=0; i<blocksize; i++ )
        {
            for( int ch=0; ch<nr_channels; ch++ )
            {
                double d = volume*getAmplitude( static_cast<double>( i*2 )/static_cast<double>( sps )+t_begin, ch );

                // Limiter with hard knee
                if( d>0.8 )
                    d=0.8+( d-0.8 )*0.5;
                else if( d<-0.8 )
                    d=-0.8-( d+0.8 )*0.5;

                if( d>0.9 )
                    d=0.9+( d-0.9 )*0.5;
                else if( d<-0.9 )
                    d=-0.9-( d+0.9 )*0.5;

                // Hard Clipping
                if( d < -1 )
                    d=-1;
                else if( d > 1 )
                    d=1;


                ( ( short* )( blocks[c_block].lpData ) )[i*nr_channels+ch] = d*MAX_V;
            }
        }

        waveOutPrepareHeader( hWaveOut, &blocks[c_block], sizeof( WAVEHDR ) );
        waveOutWrite( hWaveOut, &blocks[c_block], sizeof( WAVEHDR ) );

        p_blocks++;
        c_block=( c_block+1 )%nr_blocks;
    }

    if( dummy>1 )
        log::writeToLog( "Couldn't generate soundbuffer fast enough! Queued blocks: "+std::to_string( dummy ) );

    return;
}

void soundspace::addComposer( composer* c )
{
    c->setParent( this );
    cmpsr.push_back( c );
    return;
}

double soundspace::getAmplitude( double t, int c )
{
    double r=0;
    absolute_time=t;
    for( int i=0; i<sounds.size(); i++ )
        r+=sounds[i]->play( t, c );

    return r;
}

void soundspace::addSound( sound* snd )
{
    snd->setParent( this );
    sounds.push_back( snd );
    return;
}

double soundspace::getAbsoluteTime()
{
    return absolute_time;
}

