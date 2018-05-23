#include "composerKeyboard.hpp"

#include "../log.h"
#include "../fssimplewindow.h"
#include "soundspace.hpp"
#include "soundMultiplication.hpp"
#include "soundAddition.hpp"
#include "soundRepeater.hpp"
#include "soundOscillator.hpp"
#include "soundADSRCurve.hpp"


keyboardComposer::keyboardComposer()
{
    //ctor
    log::writeToLog( "Creating KeyboardComposer" );
    players.resize( 10 );

    for( int i=0; i<players.size(); i++ )
    {
        players[i].active=false;
        players[i].freq=base_freq*pow( 2, -3 )*pow( pow( octave,  1.0/12.0 ),  i );
        players[i].length=2;
        players[i].vol=0.3;
    }

    players[0].keycode=FSKEY_A;
    players[1].keycode=FSKEY_S;
    players[2].keycode=FSKEY_D;
    players[3].keycode=FSKEY_F;
    players[4].keycode=FSKEY_G;
    players[5].keycode=FSKEY_H;
    players[6].keycode=FSKEY_J;
    players[7].keycode=FSKEY_K;
    players[8].keycode=FSKEY_L;

    log::writeToLog( "Finished creating KeyboardComposer" );
}

keyboardComposer::~keyboardComposer()
{
    //dtor
}

void keyboardComposer::update( double t_begin, double t_end )
{
    while( t_end>=counter*bl )
    {
        if( parent==nullptr )
            log::writeToLog( "Composer can't find soundspace!", -1 );
        else
        {
            for( int i=0; i<players.size(); i++ )
            {
                if( FsGetKeyState( players[i].keycode ) )
                {
                    if( players[i].active==false )
                    {
                        sound* d = generatePianoNote( players[i].freq, players[i].length );
                        d->set_beginning( counter*bl );
                        d->set_volume( players[i].vol );

                        parent->addSound( d );
                        players[i].active=true;

                        if( FsGetKeyState( FSKEY_V ) )
                        {
                            d = generatePianoNote( players[i].freq*1.25, players[i].length );
                            d->set_beginning( ( counter+1 )*bl );
                            d->set_volume( players[i].vol );

                            parent->addSound( d );

                            d = generatePianoNote( players[i].freq*1.5, players[i].length );
                            d->set_beginning( ( counter+2 )*bl );
                            d->set_volume( players[i].vol );

                            parent->addSound( d );

                        }
                        else if( FsGetKeyState( FSKEY_B ) ) {
                            d = generatePianoNote( players[i].freq*1.2, players[i].length );
                            d->set_beginning( ( counter )*bl );
                            d->set_volume( players[i].vol );

                            parent->addSound( d );

                            d = generatePianoNote( players[i].freq*1.5, players[i].length );
                            d->set_beginning( ( counter )*bl );
                            d->set_volume( players[i].vol );

                            parent->addSound( d );

                        }
                    }
                }
                else
                    players[i].active=false;
            }
        }
        counter++;
    }
    return;
}

sound* keyboardComposer::generatePianoNote( double f, double l )
{
    /*sound_multiply* r = new sound_multiply;
    r->add_sound(new sound_oscillator(base_freq*pow(octave, oct)*pow(pow(octave, 1/intervals), intvl)));
    adsr* hull = new adsr;
    hull->set_shape(0.1*ln, 0.3*ln, 0.3, 0.3*ln, 0.3*ln);
    r->add_sound(hull);*/
    sound_add* r= new sound_add;
    for( int i=1; i<=3; i++ )
    {
        sound_multiply* dummy = new sound_multiply;
        dummy->add_sound( new sound_oscillator( f*i ) );

        adsr* hull = new adsr;
        hull->set_shape( 0.01, 0, 1, 0, ( l-0.01 )*( 1/static_cast<float>( i ) ) );
        dummy->add_sound( hull );

        dummy->set_volume( 1/static_cast<float>( i ) );

        r->add_sound( dummy );
    }

    return r;
}
