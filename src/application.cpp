#include "application.h"

#include "log.h"
#include "fssimplewindow.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#ifdef WIN32
#include <windows.h>
#endif
#ifndef MACOSX
#include <GL/gl.h>
#include <GL/glu.h>
#else
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#endif


ApplicationBase::ApplicationBase() : si_size_x( "SizeX", 800 ), si_size_y( "SizeY", 600 ), ss_theme( "Theme", "default" ) {
    //ctor
    log::writeToLog( "Creating ApplicationBase" );
    log::addTab();

    addSetting( &si_size_x );
    addSetting( &si_size_y );
    addSetting( &ss_theme );

    setVerticalFOV( 45 );

    i_state=0;

    i_mode=0;

    setMeasurementSize( 200 );

    gf_gui.setBackgroundVisibility( true );

    log::removeTab();
}

ApplicationBase::~ApplicationBase() {
    //dtor
    saveSettingsToFile( "settings.txt" );
    log::writeToLog( "Destroying ApplicationBase" );
}

void ApplicationBase::init() {
    return;
}

void ApplicationBase::initWindow() {
    log::writeToLog( "Creating window" );
    log::addTab();
    FsOpenWindow( 32, 32, si_size_x.getIntegerValue(), si_size_y.getIntegerValue(), 1 ); // 800x600 pixels, useDoubleBuffer=1
    log::removeTab();

    log::writeToLog( "Initiating OpenGL" );
    log::addTab();
    glEnable( GL_DEPTH_TEST );
    glDisable( GL_LIGHTING );
    glDepthFunc( GL_ALWAYS );
    glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );					// Black Background
    glShadeModel( GL_SMOOTH );
    glEnable( GL_TEXTURE_2D );
    glEnable( GL_BLEND );										// Enable Blending
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );		// Type Of Blending To Use
    glClear( GL_COLOR_BUFFER_BIT );

    glCullFace( GL_BACK ); // Enable Culling
    glEnable( GL_CULL_FACE );

    glEnable( GL_LINE_SMOOTH ); // Antialiased Lines
    glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );

    //glFrustum(0, size_x, 0, size_y, 0.1, 1000);
    log::removeTab();

    srand( time( NULL ) );
    //srand(0);

    return;
}

void ApplicationBase::setSize( unsigned int x, unsigned int y ) {
    if( x!=si_size_x.getIntegerValue() || y!=si_size_y.getIntegerValue() )
    {
        log::writeToLog( "Setting application size to "+std::to_string( x )+" x "+std::to_string( y ) );
        si_size_x.setIntegerValue( x );
        si_size_y.setIntegerValue( y );
        gf_gui.setSize( x, y );
    }
    return;
}

void ApplicationBase::run() {
    loadSettingsFromFile( "settings.txt" );

    setSize( si_size_x.getIntegerValue(), si_size_y.getIntegerValue() );
    gf_gui.setSize( si_size_x.getIntegerValue(), si_size_y.getIntegerValue() );
    gf_gui.setTheme( ss_theme.getStringValue() );

    log::writeToLog( "Initiating application" );
    log::addTab();

    initWindow();
    init();
    gf_gui.init();
    ss_audio.init();

    log::removeTab();
    log::nextLine();

    log::writeToLog( "Entering main loop" );
    log::nextLine();

    auto previous_frame_dur = std::chrono::steady_clock::now();
    auto current_frame_dur = std::chrono::steady_clock::now();

    while( getState()==0 )
    {
        auto frame_start = std::chrono::steady_clock::now();
        FsPollDevice();

        gf_gui.update();

        auto gui_update_end = std::chrono::steady_clock::now();

        ss_audio.update();

        auto audio_update_end = std::chrono::steady_clock::now();
        ld_audio_update_duration.push_front( std::chrono::duration_cast<std::chrono::duration<double>>( audio_update_end - gui_update_end ).count() );
        while( ld_audio_update_duration.size()>i_measurement_size )
            ld_audio_update_duration.pop_back();

        int width, height;
        FsGetWindowSize( width, height );
        setSize( width, height );


        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );	// Clear The Screen And The Depth Buffer

        glViewport( 0, 0, width, height );

        glMatrixMode( GL_PROJECTION );
        glLoadIdentity();
        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();
        glOrtho( 0, static_cast<float>( width-1 ), static_cast<float>( height-1 ), 0, -1, 1 );

        gf_gui.drawBackground();

        // if in 3D mode
        if( i_mode==3 )
        {
            glEnable( GL_DEPTH_TEST );
            glDepthFunc( GL_LEQUAL );
            glMatrixMode( GL_PROJECTION );
            glLoadIdentity();
            //glFrustum(-1, 1, -1, 1, 0.1, 1000);
            gluPerspective( d_fovy, static_cast<float>( width )/static_cast<float>( height ), 0.1, 1000 );
        }
        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();

        // MainLoop
        current_frame_dur=std::chrono::steady_clock::now();
        mainLoop( std::chrono::duration_cast<std::chrono::duration<double>>( current_frame_dur-previous_frame_dur ).count() );
        previous_frame_dur=current_frame_dur;

        auto main_loop_end = std::chrono::steady_clock::now();
        ld_main_loop_duration.push_front( std::chrono::duration_cast<std::chrono::duration<double>>( main_loop_end - audio_update_end ).count() );
        while( ld_main_loop_duration.size()>i_measurement_size )
            ld_main_loop_duration.pop_back();

        // reset to 2D mode
        glDisable( GL_DEPTH_TEST );
        glDepthFunc( GL_ALWAYS );
        glMatrixMode( GL_PROJECTION );
        glLoadIdentity();
        glOrtho( 0, static_cast<float>( width-1 ), static_cast<float>( height-1 ), 0, -1, 1 );
        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();
        gf_gui.draw();

        glFlush();

        FsSwapBuffers();
        //FsSleep(10);

        auto frame_end = std::chrono::steady_clock::now();
        ld_frame_duration.push_front( std::chrono::duration_cast<std::chrono::duration<double>>( frame_end - frame_start ).count() );
        while( ld_frame_duration.size()>i_measurement_size )
            ld_frame_duration.pop_back();
    }
    return;
}

int ApplicationBase::getState() {
    return i_state;
}

void ApplicationBase::setVerticalFOV( double f ) {
    d_fovy=f;
    return;
}

void ApplicationBase::setMode(unsigned int m ) {
    i_mode=m;
    return;
}

void ApplicationBase::setState(unsigned int s ) {
    i_state=s;
    return;
}

void ApplicationBase::setMeasurementSize(unsigned int m ) {
    i_measurement_size=m;
    return;
}

double ApplicationBase::getFPS() {
    if( ld_frame_duration.size()==0 )
        return 0;
    double r=0;
    for( auto const &i : ld_frame_duration )
        r+=i;
    return 1.0f/( r/ld_frame_duration.size() );
}

double ApplicationBase::getMainLoopDuration() {
    if( ld_main_loop_duration.size()==0 )
        return 0;
    double r=0;
    for( auto const &i : ld_main_loop_duration )
        r+=i;
    return r/ld_main_loop_duration.size();
}

double ApplicationBase::getAudioUpdateDuration() {
    if( ld_audio_update_duration.size()==0 )
        return 0;
    double r=0;
    for( auto const &i : ld_audio_update_duration )
        r+=i;
    return r/ld_audio_update_duration.size();
}
